#pragma once
#include "Hit.h"
namespace Collision{
	//点と四角の当たり判定関数(弾x,敵x,画像反対側x,弾y,敵y,画像反対側y)
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

	/*四角と四角の当たり判定(自機の始点x1,y1,対象の始点x2,y2,
	自機の透過部分を抜いた絵の位置(判定強化),size_x,size_y, size_x2, size_y2,
	対象の透過部分を抜いた絵の位置(判定強化),size_a,size_b, size_a2, size_b2)*/
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

	/*円と点の当たり判定(円の中心x1, y1, 円の半径r, 点の座標x2, y2)*/
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
