#include "Level.h"

void Level::_register_methods()
{
	godot::register_method("_ready", &Level::_ready);
	godot::register_method("_process", &Level::_process);
	godot::register_method("_physics_process", &Level::_physics_process);
	godot::register_method("pull", &Level::pull);

	godot::register_property("num_submarines", &Level::num_submarines, 0);
	godot::register_property("num_mines", &Level::num_mines, 0);
	godot::register_property("minefield_width", &Level::minefield_width, 0);
	godot::register_property("mine_texture", &Level::mine_texture, godot::Ref<godot::Texture>());
}

void Level::_init()
{
}

void Level::_ready()
{
}

void Level::_process(float delta)
{
}

void Level::_physics_process(float delta)
{
}

void Level::pull(godot::Vector2 from, float magnitude)
{
}
