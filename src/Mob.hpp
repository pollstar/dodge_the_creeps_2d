#pragma once

#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/rigid_body2d.hpp>

namespace godot {

	class Mob : public RigidBody2D {
		GDCLASS(Mob, RigidBody2D)

		AnimatedSprite2D* _animated_sprite;

	public:
		void _init() {}
		void _ready();
		void _on_visible_on_screen_notifier_2d_screen_exited();

		static void _register_methods();
	protected:
		static void _bind_methods();
	};
}
