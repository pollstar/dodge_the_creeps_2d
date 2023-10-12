#include "Main.hpp"
#include "Mob.hpp"

#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/resource_loader.hpp>

using namespace godot;

void Main::_ready()
{
	_hud = get_node<HUD>("HUD");
	_player = get_node<Player>("Player");
	_start_position = get_node<Node2D>("StartPosition");
	_mob_spawn_location = get_node<PathFollow2D>("MobPath/MobSpawnLocation");
	_mob_timer = get_node<Timer>("MobTimer");
	_score_timer = get_node<Timer>("ScoreTimer");
	_start_timer = get_node<Timer>("StartTimer");
	_music = get_node<AudioStreamPlayer>("Music");
	_death_sound = get_node<AudioStreamPlayer>("DeathSound");
	_random = (Ref<RandomNumberGenerator>) new RandomNumberGenerator();

	mob_scene = (Ref<PackedScene>) ResourceLoader::get_singleton()->load("res://gd_mob.tscn");
	_player->hide();
}

void Main::game_over()
{
	_score_timer->stop();
	_mob_timer->stop();
	_hud->show_game_over();
	_music->stop();
	_death_sound->play();
}

void Main::new_game()
{
	score = 0;
	_player->show();
	_player->start(_start_position->get_position());
	_start_timer->start();
	_hud->update_score(score);
	_hud->show_get_ready();
	_music->play();
}

void Main::_on_MobTimer_timeout()
{
	Node* mob = mob_scene->instantiate();
	
	if (!mob) {
		return;
	}
	// Choose a random location on Path2D.
	_mob_spawn_location->set_progress_ratio((real_t)_random->randf());

	// Set the mob's direction perpendicular to the path direction.
	real_t direction = _mob_spawn_location->get_rotation() + (real_t)Math_PI / 2.0;

	// Set the mob's position to a random location.
	mob->set("position", _mob_spawn_location->get_position());

	// Add some randomness to the direction.
	direction += _random->randf_range((real_t)-Math_PI / 4, (real_t)Math_PI / 4);
	mob->set("rotation", direction);

	// Choose the velocity for the mob.
	Vector2 velocity = Vector2(_random->randf_range(150.0, 250.0), 0.0);
	mob->set("linear_velocity", velocity.rotated(direction));

	// Spawn the mob by adding it to the Main scene.
	add_child(mob);
}

void Main::_on_ScoreTimer_timeout()
{
	_hud->update_score(score++);
}

void Main::_on_StartTimer_timeout()
{
	_mob_timer->start();
	_score_timer->start();
}

void Main::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("game_over"), &Main::game_over);
	ClassDB::bind_method(D_METHOD("new_game"), &Main::new_game);
	ClassDB::bind_method(D_METHOD("_on_MobTimer_timeout"), &Main::_on_MobTimer_timeout);
	ClassDB::bind_method(D_METHOD("_on_StartTimer_timeout"), &Main::_on_StartTimer_timeout);
	ClassDB::bind_method(D_METHOD("_on_ScoreTimer_timeout"), &Main::_on_ScoreTimer_timeout);
}
