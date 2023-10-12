#include "Player.hpp"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Player::_ready()
{
	_animated_sprite = get_node<godot::AnimatedSprite2D>("AnimatedSprite2D");
	_collision_shape = get_node<godot::CollisionShape2D>("CollisionShape2D");
	_inp = godot::Input::get_singleton();
	_screen_size = get_viewport_rect().size;
}

void Player::_process(const double p_delta)
{
	Vector2 velocity(0, 0);

	velocity.x = _inp->get_action_strength("ui_right") - _inp->get_action_strength("ui_left");
	velocity.y = _inp->get_action_strength("ui_down") - _inp->get_action_strength("ui_up");

	if (velocity.length() > 0) {
		velocity = velocity.normalized() * speed;
		_animated_sprite->play();
	}
	else {
		_animated_sprite->stop();
	}

	Vector2 position = get_position();
	position += velocity * (float)p_delta;
	position.x = Math::clamp(position.x, (real_t)0.0, _screen_size.x);
	position.y = Math::clamp(position.y, (real_t)0.0, _screen_size.y);
	set_position(position);

	if (velocity.x != 0) {
		_animated_sprite->set_animation("walk");
		_animated_sprite->set_flip_v(false);
		// See the note below about boolean assignment.
		_animated_sprite->set_flip_h(velocity.x < 0);
	}
	else if (velocity.y != 0) {
		_animated_sprite->set_animation("up");
		_animated_sprite->set_flip_v(velocity.y > 0);
	}
}

void Player::start(const Vector2 p_position)
{
	set_position(p_position);
	show();
	_collision_shape->set_disabled(false);
}

void Player::_register_methods()
{

}

void Player::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("get_speed"), &Player::get_speed);
	ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &Player::set_speed);
	ClassDB::add_property("Player", PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

	ClassDB::bind_method(D_METHOD("_on_body_entered"), &Player::_on_body_entered);

	ADD_SIGNAL(MethodInfo("hit"), Dictionary());
}

void Player::_on_body_entered(godot::Node2D* _body) {
	hide(); // Player disappears after being hit.
	emit_signal("hit");
	// Must be deferred as we can't change physics properties on a physics callback.
	_collision_shape->set_deferred("disabled", true);
}