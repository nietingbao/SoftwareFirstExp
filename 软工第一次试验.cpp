#include<stdio.h>
int main(){

for ( nPositionX = 0; nPositionX <= A; nPositionX+=step)
	{
	for ( nPositionY = 0; nPositionY <= A; nPositionY+=step)
	{
		isBeyond = false;
		nRds = 0;
		// ������İ�
		while(nRds <= borderRds && !isBeyond)
		{
			// �ж�Բ�ĺͱ߽�ľ��룬Բ���ܳ��������οռ�
			if ((nRds > nPositionX) || (nRds > nPositionY) || 
				(A < nPositionX + nRds) || (A < nPositionY + nRds))
				{
				// printf("%d, (%d, %d), �����˷�Χ\n", n, nPositionX, nPositionY);
					isBeyond = true;
					break;
				}
				// �ж�Բ�������е�Բ�ļ�ľ���
				// Բ�Ĳ����������е�Բ��, ��ǰ��ԲҲ���������е�Բ�ཻ
				for (int i = 0; i < n; ++i)
					{
					// ������ѻ�����Բ�ཻ���߱��ѻ�����Բ����
						if ((nRds + rdsRecord[i]) * (nRds + rdsRecord[i]) >
						(nPositionX - positionXRecord[i]) * 
						(nPositionX - positionXRecord[i]) + 
						(nPositionY - positionYRecord[i]) * (nPositionY - positionYRecord[i]))
						{
							
							isBeyond = true;
							break;
						}
					}
					// ���û�г�����������û����ԭ�е�Բ�ص�, �Ұ뾶����
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
