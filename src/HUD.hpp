#pragma once

#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/canvas_layer.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/timer.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/callable.hpp>

namespace godot {
	class HUD : public CanvasLayer {
		GDCLASS(HUD, CanvasLayer)

			Label* _score_label;
		Label* _message_label;
		Timer* _start_message_timer;
		Timer* _get_ready_message_timer;
		Button* _start_button;
		Timer* _start_button_timer;


	public:
		int p_score;

		void _init() {}
		void _ready();
		void show_get_ready();
		void show_game_over();
		void update_score(const int score);
		void _on_StartButton_pressed();
		void _on_StartMessageTimer_timeout();
		void _on_GetReadyMessageTimer_timeout();
		void _onStartButtonTimer_timeout();


		static void _register_methods();
	protected:
		static void _bind_methods();
	};
}

