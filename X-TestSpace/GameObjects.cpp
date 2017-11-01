#include "GameObjects.h"




bool doCollision(Player& player, const Wall& wall)
{
	Collision hit = collides(player.transform, player.collider, wall.transform, wall.collider);

	if (hit.penetrationDepth > 0)
	{
		resolutionStatic(player.transform.pos, player.body.velocity, hit, 0.25f);
		return true;
	}

	return false;
}

bool doCollision(Player& player, const Ball& ball)
{
	Collision hit = collides(player.transform, player.collider, ball.transform, ball.collider);

	if (hit.penetrationDepth > 0)
	{
		resolutionStatic(player.transform.pos, player.body.velocity, hit, 0.25f);
		return true;
	}

	return false;
}

bool doCollision(Ball& ball, Wall& wall)
{
	Collision hit = collides(ball.transform, ball.collider, wall.transform, wall.collider);

	if (hit.penetrationDepth > 0)
	{
		resolutionStatic(ball.transform.pos, ball.body.velocity, hit, 0.25f);
		return true;
	}

	return false;
}
