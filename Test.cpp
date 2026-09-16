#include <iostream>
#include <string>
using namespace std;

struct MayTinh
{
    int maSo;
    string tenMay;
    string heDieuHanh;
    string taiKhoan;
    string matKhau;
    string doiMay;
    int namSanXuat;

    void xuatThongTin()
    {
        cout << "ID: " << maSo << endl;
        cout << "Ten may: " << tenMay << endl;
        cout << "HDH: " << heDieuHanh << endl;
        cout << "Username: " << taiKhoan << endl;
        cout << "Password: " << matKhau << endl;
        cout << "Model: " << doiMay << endl;
        cout << "Year: " << namSanXuat << endl;
    }
};

void nhapThongTinMay(MayTinh &m)
{
    cout << "Nhap ID: ";
    cin >> m.maSo;
    cin.ignore();

    cout << "Nhap ten may: ";
    getline(cin, m.tenMay);

    cout << "Nhap HDH: ";
    getline(cin, m.heDieuHanh);

    cout << "Nhap username: ";
    getline(cin, m.taiKhoan);

    cout << "Nhap password: ";
    getline(cin, m.matKhau);

    cout << "Nhap model: ";
    getline(cin, m.doiMay);

    cout << "Nhap year: ";
    cin >> m.namSanXuat;
}

int timViTriTheoID(MayTinh danhSach[], int soLuong, int idCanTim)
{
    for (int i = 0; i < soLuong; i++)
    {
        if (danhSach[i].maSo == idCanTim)
            return i;
    }
    return -1;
}

int timViTriTheoTen(MayTinh danhSach[], int soLuong, const string &tenCanTim)
{
    for (int i = 0; i < soLuong; i++)
    {
        if (danhSach[i].tenMay == tenCanTim)
            return i;
    }
    return -1;
}

void inMayTheoNam(MayTinh danhSach[], int soLuong, int namGioiHan)
{
    bool coKetQua = false;

    for (int i = 0; i < soLuong; i++)
    {
        if (danhSach[i].namSanXuat >= namGioiHan)
        {
            danhSach[i].xuatThongTin();
            coKetQua = true;
        }
    }

    if (!coKetQua)
        cout << "Khong tim thay computer!" << endl;
}

void inTaiKhoanTheoID(MayTinh danhSach[], int soLuong, int idCanTim)
{
    int vt = timViTriTheoID(danhSach, soLuong, idCanTim);

    if (vt != -1)
    {
        cout << "Username: " << danhSach[vt].taiKhoan << endl;
        cout << "Password: " << danhSach[vt].matKhau << endl;
    }
    else
    {
        cout << "Khong tim thay Computer co ID = " << idCanTim << endl;
    }
}

class PhongMay
{
private:
    string maPhong;

public:
    PhongMay(string ma) : maPhong(ma) {}

    void hienThi()
    {
        cout << "\n========== LAB ==========" << endl;
        cout << "Ma phong: " << maPhong << endl;
        cout << "Chuc nang: Phong may tinh" << endl;
        cout << "=========================" << endl;
    }
};

int main()
{
    const int SLmax = 100;
    MayTinh danhSachMay[SLmax];
    int tongSo;

    cout << "Nhap so luong computer: ";
    cin >> tongSo;

    for (int i = 0; i < tongSo; i++)
    {
        cout << "\n========== COMPUTER " << i + 1 << " ==========\n";
        nhapThongTinMay(danhSachMay[i]);
    }

    cout << "\n\n******** DANH SACH COMPUTER ********\n";
    for (int i = 0; i < tongSo; i++)
    {
        danhSachMay[i].xuatThongTin();
    }

    int idTim;
    cout << "\nNhap ID can tim: ";
    cin >> idTim;

    int viTriID = timViTriTheoID(danhSachMay, tongSo, idTim);
    if (viTriID != -1)
    {
        cout << "\nTim thay Computer:\n";
        danhSachMay[viTriID].xuatThongTin();
    }
    else
    {
        cout << "Khong tim thay!" << endl;
    }

    cin.ignore();
    string tenTim;
    cout << "\nNhap ten may can tim: ";
    getline(cin, tenTim);

    int viTriTen = timViTriTheoTen(danhSachMay, tongSo, tenTim);
    if (viTriTen != -1)
    {
        cout << "\nTim thay Computer:\n";
        danhSachMay[viTriTen].xuatThongTin();
    }
    else
    {
        cout << "Khong tim thay!" << endl;
    }

    int namTim;
    cout << "\nNhap nam can tim: ";
    cin >> namTim;

    cout << "\n===== CAC COMPUTER CO YEAR >= " << namTim << " =====\n";
    inMayTheoNam(danhSachMay, tongSo, namTim);

    cout << "\nNhap ID de lay Username va Password: ";
    cin >> idTim;

    cout << "\n===== USERNAME & PASSWORD =====\n";
    inTaiKhoanTheoID(danhSachMay, tongSo, idTim);

    PhongMay lab104("AS-104");
    lab104.hienThi();

    return 0;
}