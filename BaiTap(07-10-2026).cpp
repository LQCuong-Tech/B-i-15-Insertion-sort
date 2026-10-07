#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
//Luong Quoc Cuong 24810310195
// C헧 1:
struct KhachHang {
    int maKH;
    string tenKH;
    string soDienThoai;
    double tongTienThanhToan;
};

void inTieuDe() {
    cout << left 
         << setw(12) << "Ma KH" 
         << setw(25) << "Ten khach hang" 
         << setw(15) << "So dien thoai" 
         << setw(20) << "Tong tien (VND)" << endl;
    cout << string(72, '-') << endl;
}

void xuatKhachHang(const KhachHang& kh) {
    cout << left 
         << setw(12) << kh.maKH 
         << setw(25) << kh.tenKH 
         << setw(15) << kh.soDienThoai 
         << setw(20) << kh.tongTienThanhToan << endl;
}

// C헧 2:
void nhapDanhSach(vector<KhachHang>& ds, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin khach hang thu " << i + 1 << " ---" << endl;
        KhachHang kh;
        cout << "Ma khach hang: ";
        cin >> kh.maKH;
        cin.ignore(); 
        cout << "Ten khach hang: ";
        getline(cin, kh.tenKH);

        cout << "So dien thoai: ";
        getline(cin, kh.soDienThoai);

        cout << "Tong tien thanh toan: ";
        cin >> kh.tongTienThanhToan;

        ds.push_back(kh);
    }
}

// C헧 3:
void xuatDanhSach(const vector<KhachHang>& ds) {
    if (ds.empty()) {
        cout << "Danh sach khach hang trong!" << endl;
        return;
    }
    
    inTieuDe();
    for (size_t i = 0; i < ds.size(); i++) {
        xuatKhachHang(ds[i]);
    }
}

// C헧 4:
void insertionSort(vector<KhachHang>& ds) {
    int n = ds.size();
    for (int i = 1; i < n; i++) {
        KhachHang key = ds[i];
        int j = i - 1;

        while (j >= 0 && ds[j].tongTienThanhToan > key.tongTienThanhToan) {
            ds[j + 1] = ds[j];
            j--;
        }
        ds[j + 1] = key;
    }
}

// C헧 5:
void timKiemNhiPhanTheoTien(const vector<KhachHang>& ds, double X) {
    int left = 0;
    int right = ds.size() - 1;
    int foundIdx = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ds[mid].tongTienThanhToan == X) {
            foundIdx = mid;
            break;
        }
        if (ds[mid].tongTienThanhToan < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (foundIdx == -1) {
        cout << "\nKhong tim thay khach hang nao co tong tien thanh toan bang " 
             << X << " VND." << endl;
        return;
    }

    int start = foundIdx;
    while (start > 0 && ds[start - 1].tongTienThanhToan == X) {
        start--;
    }

    int end = foundIdx;
    while (end < (int)ds.size() - 1 && ds[end + 1].tongTienThanhToan == X) {
        end++;
    }

    cout << "\n=== KET QUA TIM KIEM KHACH HANG CO TONG TIEN = " 
         << X << " VND ===" << endl;
    inTieuDe();
    for (int i = start; i <= end; i++) {
        xuatKhachHang(ds[i]);
    }
}

// C헧 6:
int main() {
    int n;
    do {cout << "Nhap so luong khach hang n: ";cin >> n;
	} while(n<=0);

    vector<KhachHang> dsKhachHang;
    nhapDanhSach(dsKhachHang, n);
    cout << "\n================ DANH SACH VUA NHAP ================" << endl;
    xuatDanhSach(dsKhachHang);

    insertionSort(dsKhachHang);
    cout << "\n======== DANH SACH SAU KHI SAP XEP (INSERTION SORT) ========" << endl;
    xuatDanhSach(dsKhachHang);

    double X;
    cout << "\nNhap tong tien thanh toan X can tim: ";
    cin >> X;
    timKiemNhiPhanTheoTien(dsKhachHang, X);

    return 0;
}
