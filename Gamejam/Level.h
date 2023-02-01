#pragma once
#include "Common.h"
#include <Node2D.hpp>
#include <Texture.hpp>

class Level : public godot::Node2D
{
	GODOT_CLASS(Level, godot::Node2D);


	int num_submarines{ 0 };
	int num_mines{ 0 };
	int minefield_width{ 0 };
	godot::Ref<godot::Texture> mine_texture{};

public:
	static void _register_methods();
	void _init();

	void _ready();
	void _process(float delta);
	void _physics_process(float delta);

	void pull(godot::Vector2 from, float magnitude);
;};

