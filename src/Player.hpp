#pragma once

#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/collision_shape2d.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/input.hpp>

namespace godot {

	class Player : public Area2D {
		GDCLASS(Player, Area2D)

		AnimatedSprite2D* _animated_sprite;
		CollisionShape2D* _collision_shape;
		Input* _inp;
		Vector2 _screen_size; // Size of the game window.

	public:
		float speed = 400; // How fast the player will move (pixels/sec).

		void _init() {}
		void _ready();
		void _process(const double p_delta);
		void start(const Vector2 p_position);
		void _on_body_entered(Node2D* _body);

		static void _register_methods();

		void set_speed(const float p_speed) {
			speed = p_speed;
		}
		float get_speed() const { return speed; };

	protected:
		static void _bind_methods();

	};
}