#pragma once
namespace Collision{
	//�_�Ǝl�p�̓����蔻��(�ex,�Gx,�摜���Α�x,�ey,�Gy,�摜���Α�y)
	bool hit(float size_x1, float size_x2, float width, float size_y1, float size_y2, float height);

	/*�l�p�Ǝl�p�̓����蔻��(���@�̎n�_x1,y1,�Ώۂ̎n�_x2,y2,
	���@�̓��ߕ����𔲂����G�̈ʒu(���苭��),size_x,size_y, size_x2, size_y2,
	�Ώۂ̓��ߕ����𔲂����G�̈ʒu(���苭��),size_a,size_b, size_a2, size_b2)*/
	bool hit2(float x1, float y1, float x2, float y2,
		float size_x, float size_y, float size_x2, float size_y2,
		float size_a, float size_b, float size_a2, float size_b2);
	
	/*�~�Ɠ_�̓����蔻��(�~�̒��Sx1, y1, �~�̔��ar, �_�̍��Wx2, y2)*/
	bool hit3(float x1, float y1, float r, float x2, float y2);

	/*�~�Ɖ~�̂����蔻��(�~1�̒��Sx1, y1, �~1�̔��ar1, �~2�̔��ax2, y2, �~2�̔��ar2)*/
	bool hit4(float x1, float y1, float r1, float x2, float y2, float r2);

}

