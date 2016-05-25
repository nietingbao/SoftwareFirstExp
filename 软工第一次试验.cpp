#include<stdio.h>
int main(){

for ( nPositionX = 0; nPositionX <= A; nPositionX+=step)
	{
	for ( nPositionY = 0; nPositionY <= A; nPositionY+=step)
	{
		isBeyond = false;
		nRds = 0;
		// 求出最大的半
		while(nRds <= borderRds && !isBeyond)
		{
			// 判断圆心和边界的距离，圆不能超出正方形空间
			if ((nRds > nPositionX) || (nRds > nPositionY) || 
				(A < nPositionX + nRds) || (A < nPositionY + nRds))
				{
				// printf("%d, (%d, %d), 超出了范围\n", n, nPositionX, nPositionY);
					isBeyond = true;
					break;
				}
				// 判断圆心与已有的圆心间的距离
				// 圆心不能落在已有的圆中, 当前的圆也不能与已有的圆相交
				for (int i = 0; i < n; ++i)
					{
					// 如果与已画出的圆相交或者被已画出的圆包含
						if ((nRds + rdsRecord[i]) * (nRds + rdsRecord[i]) >
						(nPositionX - positionXRecord[i]) * 
						(nPositionX - positionXRecord[i]) + 
						(nPositionY - positionYRecord[i]) * (nPositionY - positionYRecord[i]))
						{
							
							isBeyond = true;
							break;
						}
					}
					// 如果没有超出正方形且没有与原有的圆重叠, 且半径更大
					if (nRds > nMaxRds)
						{
							nMaxRds = nRds;
							nBestPositionX = nPositionX;
							nBestPositionY = nPositionY;
						}
						nRds+=step;
					}
				}
}
