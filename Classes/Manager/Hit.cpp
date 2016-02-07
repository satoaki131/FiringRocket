#pragma once
#include "Hit.h"
namespace Collision{
	//�_�Ǝl�p�̓����蔻��֐�(�ex,�Gx,�摜���Α�x,�ey,�Gy,�摜���Α�y)
	bool hit(float size_x1, float size_x2, float width, float size_y1, float size_y2, float height) {
		bool Shot_hit1 = false;
		if (size_x1 > size_x2){
			if (size_x1  < size_x2 + width){
				if (size_y1  > size_y2){
					if (size_y1 < size_y2 + height){
						return true;
					}
				}
			}
		}
		return false;
	}

	/*�l�p�Ǝl�p�̓����蔻��(���@�̎n�_x1,y1,�Ώۂ̎n�_x2,y2,
	���@�̓��ߕ����𔲂����G�̈ʒu(���苭��),size_x,size_y, size_x2, size_y2,
	�Ώۂ̓��ߕ����𔲂����G�̈ʒu(���苭��),size_a,size_b, size_a2, size_b2)*/
	bool hit2(float x1, float y1, float x2, float y2,
		float size_x, float size_y, float size_x2, float size_y2,
		float size_a, float size_b, float size_a2, float size_b2){
		bool Shot_hit2 = false;
		if ((x1 + size_x) > (x2 + size_a)){
			if ((x1 + size_x2) < (x2 + size_a2)){
				if ((y1 + size_y) > (y2 + size_b)){
					if ((y1 + size_y2) < (y2 + size_b2)){
						return true;
					}
				}
			}
		}
		return false;
	}

	/*�~�Ɠ_�̓����蔻��(�~�̒��Sx1, y1, �~�̔��ar, �_�̍��Wx2, y2)*/
	bool hit3(float x1, float y1, float r,float x2, float y2){
		bool circle_hit = false;
		if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) < (r*r)){
			return true;
		}
		return false;
	}

	bool hit4(float x1, float y1, float r1, float x2, float y2, float r2)
	{
		bool circle_hit = false;
		if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) < (r1 + r2)*(r1 + r2)){
			return true;
		}
		return false;
	}
}
