#pragma once

#include <godot_cpp/classes/audio_stream_player.hpp>
#include <godot_cpp/classes/canvas_layer.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/path_follow2d.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>
#include <godot_cpp/classes/timer.hpp>

#include "player.hpp"
#include "Mob.hpp"
#include "HUD.hpp"

namespace godot {

	class Main : public Node {
		GDCLASS(Main, godot::Node)

		int score;
		HUD* _hud;
		Player* _player;
		Node2D* _start_position;
		PathFollow2D* _mob_spawn_location;
		Timer* _mob_timer;
		Timer* _score_timer;
		Timer* _start_timer;
		AudioStreamPlayer* _music;
		AudioStreamPlayer* _death_sound;
		Ref<RandomNumberGenerator> _random;
		
	public:
		Ref<PackedScene> mob_scene;

		void _init() {}
		void _ready();
		void game_over();
		void new_game();
		void _on_MobTimer_timeout();
		void _on_ScoreTimer_timeout();
		void _on_StartTimer_timeout();

		static void _register_methods() {};
	protected:
		static void _bind_methods();
	};
}