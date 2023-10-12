#include "Mob.hpp"

#include <godot_cpp/classes/random_number_generator.hpp>
#include <godot_cpp/classes/sprite_frames.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>


using namespace godot;

void Mob::_ready() {
	godot::Ref<godot::RandomNumberGenerator> random = new RandomNumberGenerator();

	_animated_sprite = get_node<AnimatedSprite2D>("AnimatedSprite2D");
	_animated_sprite->play();

	PackedStringArray mob_types = _animated_sprite->get_sprite_frames()->get_animation_names();
	_animated_sprite->set_animation(mob_types[random->randi() % mob_types.size()]);
}

void godot::Mob::_on_visible_on_screen_notifier_2d_screen_exited()
{
	queue_free();
}

void godot::Mob::_register_methods()
{
}

void godot::Mob::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("_on_visible_on_screen_notifier_2d_screen_exited"), &Mob::_on_visible_on_screen_notifier_2d_screen_exited);
}
