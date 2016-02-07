#pragma once
namespace Collision{
	//“_‚ÆlŠp‚Ì“–‚½‚è”»’è(’ex,“Gx,‰æ‘œ”½‘Î‘¤x,’ey,“Gy,‰æ‘œ”½‘Î‘¤y)
	bool hit(float size_x1, float size_x2, float width, float size_y1, float size_y2, float height);

	/*lŠp‚ÆlŠp‚Ì“–‚½‚è”»’è(©‹@‚Ìn“_x1,y1,‘ÎÛ‚Ìn“_x2,y2,
	©‹@‚Ì“§‰ß•”•ª‚ğ”²‚¢‚½ŠG‚ÌˆÊ’u(”»’è‹­‰»),size_x,size_y, size_x2, size_y2,
	‘ÎÛ‚Ì“§‰ß•”•ª‚ğ”²‚¢‚½ŠG‚ÌˆÊ’u(”»’è‹­‰»),size_a,size_b, size_a2, size_b2)*/
	bool hit2(float x1, float y1, float x2, float y2,
		float size_x, float size_y, float size_x2, float size_y2,
		float size_a, float size_b, float size_a2, float size_b2);
	
	/*‰~‚Æ“_‚Ì“–‚½‚è”»’è(‰~‚Ì’†Sx1, y1, ‰~‚Ì”¼Œar, “_‚ÌÀ•Wx2, y2)*/
	bool hit3(float x1, float y1, float r, float x2, float y2);

	/*‰~‚Æ‰~‚Ì‚ ‚½‚è”»’è(‰~1‚Ì’†Sx1, y1, ‰~1‚Ì”¼Œar1, ‰~2‚Ì”¼Œax2, y2, ‰~2‚Ì”¼Œar2)*/
	bool hit4(float x1, float y1, float r1, float x2, float y2, float r2);

}

