#include "HUD.hpp"

using namespace godot;

void HUD::_ready()
{
	_score_label = get_node<Label>("ScoreLabel");
	_message_label = get_node<Label>("MessageLabel");
	_start_message_timer = get_node<Timer>("MessageTimer");
	_get_ready_message_timer = get_node<Timer>("GetReadyMessageTimer");
	_start_button = get_node<Button>("StartButton");
	_start_button_timer = get_node<Timer>("StartButtonTimer");
	
	_on_StartMessageTimer_timeout();
}

void HUD::show_get_ready()
{
	_message_label->set_text("Get Ready");
	_message_label->show();
	_get_ready_message_timer->start();
}

void HUD::show_game_over()
{
	_message_label->set_text("Game Over");
	_message_label->show();
	_start_message_timer->start();
}

void HUD::update_score(const int score)
{
	_score_label->set_text(Variant(score));
}

void HUD::_on_StartButton_pressed()
{
	_start_button_timer->stop();
	_start_button->hide();
	emit_signal("start_game");
}

void HUD::_on_StartMessageTimer_timeout()
{
	_message_label->set_text("Dodge the\nCreeps");
	_message_label->show();
	_start_button_timer->start();
}

void HUD::_on_GetReadyMessageTimer_timeout()
{
	_message_label->hide();
}

void HUD::_onStartButtonTimer_timeout()
{
	_start_button->show();
}

void HUD::_register_methods()
{
}

void HUD::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("show_get_ready"), &HUD::show_get_ready);
	ClassDB::bind_method(D_METHOD("show_game_over"), &HUD::show_game_over);
	ClassDB::bind_method(D_METHOD("update_score"), &HUD::update_score);
	ClassDB::bind_method(D_METHOD("_on_StartButton_pressed"), &HUD::_on_StartButton_pressed);
	ClassDB::bind_method(D_METHOD("_on_StartMessageTimer_timeout"), &HUD::_on_StartMessageTimer_timeout);
	ClassDB::bind_method(D_METHOD("_on_GetReadyMessageTimer_timeout"), &HUD::_on_GetReadyMessageTimer_timeout);
	ClassDB::bind_method(D_METHOD("_onStartButtonTimer_timeout"), &HUD::_onStartButtonTimer_timeout);

	ADD_SIGNAL(MethodInfo("start_game"));
}
