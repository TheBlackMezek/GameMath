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

bool doCollision(Player& player, Ball& ball)
{
	Collision hit = collides(player.transform, player.collider, ball.transform, ball.collider);

	if (hit.penetrationDepth > 0)
	{
		resolutionDynamic(player.transform.pos, player.body.velocity, player.body.mass,
			ball.transform.pos, ball.body.velocity, ball.body.mass, hit, 0.25f);
		return true;
	}

	return false;
}

bool doCollision(Ball& ball, const Wall& wall)
{
	Collision hit = collides(ball.transform, ball.collider, wall.transform, wall.collider);

	if (hit.penetrationDepth > 0)
	{
		resolutionStatic(ball.transform.pos, ball.body.velocity, hit, 0.25f);
		return true;
	}

	return false;
}
