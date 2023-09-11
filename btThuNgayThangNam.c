#include <stdio.h>
#include <stdbool.h>


//ham kiem tra nam nhuan 

bool laNamNhuan(int nYear)
{
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		return true;
	}
	return false;
}

//ham kiem tra so ngay trong thang

int tinhSoNgayTrongThang(int nMonth, int nYear)
{
	int nNumOfDays;

	switch (nMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: 
		nNumOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11: 
		nNumOfDays = 30;
		break;
	case 2:
		if (laNamNhuan(nYear))
		{
			nNumOfDays = 29;
		}
		else
		{
			nNumOfDays = 28;
		}
		break;
	}

	return nNumOfDays;
}

//ham kiem tra so ngay trong nam

int SoNgayTrongNam(int nYear)
        {
            if (laNamNhuan(nYear)) return 366;
            return 365;
        }

//ham tinh so ngay tu ngay 01/01/0001 -> 31/12/nYear-1 
int SoNgayTruocNam(int nYear)
        {
            int TongSoNgayTruoc = 0;
            for (int i = 1; i < nYear; i += 1)
                TongSoNgayTruoc += SoNgayTrongNam(i);
            return TongSoNgayTruoc;
        }
//ham tinh so ngay tu ngay 01/01/nYear -> 01/nMonth/nYear
int SoNgayTruocThang(int nMonth, int nYear)
        {
            int SoNgay=0;
            for (int i = 1; i < nMonth; i ++)
                SoNgay += tinhSoNgayTrongThang(i, nYear);
            return SoNgay;
        }

//ham tinh tong so ngay tu 01/01/0001 -> nDay/nMonth/nYear

int TongSoNgay(int nYear, int nMonth, int nDay)
        {
            return SoNgayTruocNam(nYear) + SoNgayTruocThang(nMonth, nYear) + nDay;
        }



void NgayTrongTuan(int nYear, int nMonth, int nDay)
        {
            switch (TongSoNgay(nYear, nMonth, nDay)%7)
            {
                case 0: printf("Chu nhat"); break;
                case 1: printf("Thu hai"); break;
                case 2: printf("Thu ba"); break;
                case 3: printf("Thu tu"); break;
                case 4: printf("Thu nam"); break;
                case 5: printf("Thu sau"); break;
                default: printf("Thu bay"); break;
            }
        }

int main(){
   NgayTrongTuan(2023, 9, 11);
}