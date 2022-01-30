#pragma once

const enum class Difficulty
{
	EASY 
		= (0b1 << 0), // 1
	MEDIUM 
		= (0b1 << 1), // 2
	HARD 
		= (0b1 << 2), // 4
	EXPERT 
		= (0b1 << 3), // 8
};