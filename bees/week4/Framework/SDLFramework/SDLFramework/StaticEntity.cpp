#include "StaticEntity.h"

# define M_PI           3.14159265358979323846  /* pi */


StaticEntity::StaticEntity(double x, double y, int width, int height)
	:BaseGameEntity(x, y, width, height)
{
}

void StaticEntity::draw()
{
	if (m_texture)
	{
		int x = m_position.getX();
		int y = m_position.getY();
		FWApplication::GetInstance()->DrawTexture(m_texture, x, y, m_width, m_height);
	}
}


