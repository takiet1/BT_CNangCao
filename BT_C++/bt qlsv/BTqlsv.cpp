
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

typedef enum{
    NU,
    NAM
} typeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNGBINH,
    YEU
} typeHocLuc;

class SinhVien{
    private:
        int ID;
        string NAME;
        int TUOI;
        typeGioiTinh GIOITINH;
        typeHocLuc HOCLUC;
        double DIEMTB;
        double DIEMLY, DIEMTOAN, DIEMVAN;
    public:
        SinhVien(string name, int tuoi, typeGioiTinh gioitinh, double diemLy, double diemToan, double diemVan);
        double getDiemTB() {
             DIEMTB = (DIEMLY+DIEMTOAN+DIEMVAN)/3; 
             return DIEMTB; 
        }
        typeHocLuc getHocLuc(){
            //DIEMTB = (DIEMLY+DIEMTOAN+DIEMVAN)/3;
            if(DIEMTB >= 8) HOCLUC = GIOI;
            else if (DIEMTB >= 6.5) HOCLUC = KHA;
            else if(DIEMTB >= 5) HOCLUC = TRUNGBINH;
            else HOCLUC = YEU;
            return HOCLUC;
        };

        int getID() {return ID;};
        string getName() {return NAME;};
        int getTuoi()  {return TUOI;};
        typeGioiTinh getGioiTinh() {return GIOITINH;};
        double getDiemToan() {return DIEMTOAN;};
        double getDiemLy() {return DIEMLY;};
        double getDiemVan() {return DIEMVAN;};

        

        void setName(){
        string new_name;
        cout<<"Nhap ten: ";
        cin>>new_name;
        NAME = new_name;
        }

        void setGender(){
        int number;
        while (1){
            cout << "Nhap gioi tinh: \n1. Nam\n2. Nu\n";
            cin>>number;
            if(number == 1) {GIOITINH = NAM; break;}
            else if (number == 2) {GIOITINH = NU; break;}
            else if (number != 1 && number != 2) {cout<<"Gioi tinh khong thoa man\nNhap lai: ";} 
            else break;     
            }
        } 

        void setAge(){
        int tuoi;
        while (1){
            cout<<"Nhap tuoi: ";
            cin>>tuoi;
            TUOI = tuoi;
            if(tuoi > 50 || tuoi < 18){
                cout<<"Tuoi nhap khong hop le!\nNhap lai: ";
            }
            else break;
            }
        }

        void setToan(){
        double diemtoan;
        while (1){
            cout<<"Nhap diem toan: ";
            cin>>diemtoan;
            DIEMTOAN = diemtoan;
            if(diemtoan < 0 || diemtoan > 10){
                cout<<"Diem nhap khong hop le!\nNhap lai: ";
            }
            else break;
            }
        
        }

        void setVan(){
        double diemvan;
        while (1){
            cout<<"Nhap diem van: ";
            cin>>diemvan;
            DIEMVAN = diemvan;
            if(diemvan < 0 || diemvan > 10){
                cout<<"Diem nhap khong hop le!\nNhap lai: ";
            }
            else break;
            }
    
        }

        void setLy(){
        double diemly;
        while (1){
            cout<<"Nhap diem ly: ";
            cin>>diemly;
            DIEMLY = diemly;
            if(diemly < 0 || diemly > 10){
                cout<<"Diem nhap khong hop le!\nNhap lai: ";
            }
            else break;
            }
        
        }

        void information(){
        cout<<"-----------------------------------\n";
        cout<<"ID: "<<ID<<endl;
        cout<<"Ten: "<<NAME<<endl;
        cout<<"Tuoi: "<<TUOI<<endl;
        cout<<"Gioi Tinh: "<<GIOITINH<<endl;
        cout<<"Diem Toan: "<<DIEMTOAN<<endl;
        cout<<"Diem Van: "<<DIEMVAN<<endl;
        cout<<"Diem Ly: "<<DIEMLY<<endl;
        cout<<"Diem TB: "<<DIEMTB<<endl; 
        }
};


SinhVien::SinhVien(string name, int tuoi, typeGioiTinh gioitinh, double ly, double toan, double van){
    static int id = 1000;
    ID = id++;
    
    NAME = name;
    TUOI = tuoi;
    GIOITINH = gioitinh;
    DIEMLY = ly;
    DIEMTOAN = toan;
    DIEMVAN = van;
}

     list<SinhVien> database;


void ThemSinhVien(){
    string name;
    int tuoi;
    typeGioiTinh gioitinh;
    double diemtoan, diemvan, diemly;

    while(1){
    
        cout << "Nhap ten sinh vien: "<<endl;
        cin >> name;


        while (1){
        cout << "Nhap tuoi: "<<endl;
        cin >> tuoi;
        if (tuoi > 50 || tuoi < 10){
            cout << "Tuoi nhap khong hop le !"<<endl;
            
            }
        else break;
        }

        while (1){
        cout << "Chon gioi tinh"<<endl <<"Nhap phim: \n" << "1. Nam\n2. Nu\n";
        int ch; cin >> ch; 
        if (ch == 1) { 
            gioitinh = NAM; 
            break;
        }
        else if (ch == 2) {
            gioitinh = NU; 
            break;
        } 
        else if (ch != 1 && ch != 2)  cout << "Nhap lai: \n";
        else break;
        }

    
        while (1){
            cout << "Nhap diem toan: "<<endl;
            cin >> diemtoan;
            if (diemtoan > 10 || diemtoan < 0){
                cout << "Diem nhap khong hop le !"<<endl;
                
            }
            else break;
        }

        
        while (1){
            cout << "Nhap diem van: "<<endl;
            cin >> diemvan;
            if (diemvan > 10 || diemvan < 0){
                cout << "Diem nhap khong hop le !"<<endl;
                
            }
            else break;
        }

    
        while (1){
            cout << "Nhap diem ly : "<<endl;
            cin >> diemly;
            if (diemly > 10 || diemly < 0){
                cout << "Diem nhap khong hop le !"<<endl;
                
            }
            else break;
        }
    SinhVien sv(name, tuoi, gioitinh, diemly, diemtoan, diemvan);
    database.push_back(sv);
    int chtt;
    cout << "Tiep tuc them thong tin sinh vien: \nChon 1.Tiep tuc \t2. Thoat\n";
    cin >> chtt;
    if (chtt == 2) return;
   
    }
    
}


void CapNhatSVID(){
    int id;
    cout<<"Nhap ID sinh vien can cap nhat: ";
    cin>>id;
    for(SinhVien &sv : database){
        if (sv.getID() == id){
        
            cout<<"1. Nhap ten"<<endl;
            cout<<"2. Nhap gioi tinh"<<endl;
            cout<<"3. Nhap tuoi"<<endl;
            cout<<"4. Nhap diem toan"<<endl;
            cout<<"5. Nhap diem van"<<endl;
            cout<<"6. Nhap diem ly"<<endl;
            cout<<"7. Nhap ten"<<endl;
            cout<<"0. Thoat"<<endl;
            cout<<"Chon phim: ";
            int options;
            cin>>options;
            switch (options)
            {
            case 1:
                sv.setName();
                break;
            case 2:
                sv.setGender();
                break;
            case 3:
                sv.setAge();
                break;
            case 4:
                sv.setToan();
                break;
            case 5:
                sv.setVan();
                break;
            case 6:
                sv.setLy();
                break; 
            }
            if(options > 6 || options < 0){
                cout<<"Phim khong hop le! Nhap lai: \n";
            }
           
            cout<<"Da sua xong\n";
            
        }
     }
}

void XoaSVID(){
    int id;
    cout<<"Nhap ID sinh vien can xoa: ";
    cin>>id;
    list<SinhVien>::iterator vitrixoa = database.begin();
    for(SinhVien sv : database){
        if(sv.getID() == id){
            database.erase(vitrixoa);
            cout<<"Da xoa thanh cong\n";
        }
        else if (sv.getID() != id){
        cout<<"ID khong ton tai!\n";
        }
        else break;
        
        
        }
}


void TimSVTen(){
    string find_name;
    cout<<"Nhap ten sinh vien can tim: ";
    cin>>find_name;

    bool check = false;
    for(SinhVien sv:database){
        if(sv.getName() == find_name){
            sv.information();
            check = true;
        }
    }
    if(check==false) cout<<"Ten khong ton tai\n";
}

void SapXepSVDTB(){
    list<SinhVien>::iterator sv1, sv2;

    for (sv1 = database.begin(); sv1 != database.end(); ++sv1) {
        for (sv2 = next(sv1); sv2 != database.end(); ++sv2) {
            if (sv1->getDiemTB() > sv2->getDiemTB()) {
                swap(*sv1, *sv2);
            }
        }
    }
}


void SapXepSVTen(){
    list<SinhVien>::iterator sv1, sv2;

    for (sv1 = database.begin(); sv1 != database.end(); ++sv1) {
        for (sv2 = next(sv1); sv2 != database.end(); ++sv2) {
            if (sv1->getName() > sv2->getName()) {
                swap(*sv1, *sv2);
            }
        }
    }
}



void HienThi(){
    for (SinhVien sv : database){
        sv.information();
    }
}

int main()
{
   
    while(1){
        int options;
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"Cac chuc nang!"<<endl;
        cout << "1. Them sinh vien" << endl;
        cout << "2. Cap nhat thong tin sinh vien" << endl;
        cout << "3. Xoa sinh vien theo ID" << endl;
        cout << "4. Tim kiem sinh vien theo ten" << endl;
        cout << "5. Sap xep sinh vien theo diem trung binh" << endl;
        cout << "6. Sap xep sinh vien theo ten" << endl;
        cout << "7. Hien thi danh sach sinh vien" << endl;
        cout << "8. Thoat" << endl;
        cout<<"Chon chuc nang: ";
        cin>>options;


        switch (options)
        {
        case 1:
            ThemSinhVien();
            break;
        case 2:
            CapNhatSVID();
            break;
        case 3:
            XoaSVID();
            break;
        case 4:
            TimSVTen();
            break;
        case 5:
            SapXepSVDTB();
            break;
        case 6:
            SapXepSVTen();
            break;    
        case 7:
            HienThi();
            break;
        case 8:
            cout << "Da Thoat" << endl;
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}