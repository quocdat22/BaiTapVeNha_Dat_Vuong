#include <stdio.h>

// Cấu trúc lưu thông tin một môn học
struct Subject{
    char maMon[10];      // Mã môn học
    char tenMon[50];     // Tên môn học
    int soTinChi;        // Số tín chỉ
    float diem;          // Điểm của môn học
};

// Cấu trúc lưu thông tin một sinh viên
struct Student{
    char maSoSinhVien[10];  // Mã số sinh viên
    char hoTen[50];         // Họ tên sinh viên
    Subject nhapMonLapTrinh;  // Điểm môn Nhập môn lập trình
    Subject toanA1;           // Điểm môn Toán A1
    Subject toanA2;           // Điểm môn Toán A2
    Subject vatLyKyThuat;     // Điểm môn Vật lý kỹ thuật
    Subject anhVan;           // Điểm môn Anh văn
    float diemTrungBinh;      // Điểm trung bình tích lũy
};

int main() {
    // Khởi tạo một sinh viên mẫu để minh họa
    
    Student student = {
       "SV001",                        // Mã số sinh viên
       "Nguyen Van A",                 // Họ tên
       {"IT101", "Nhap mon lap trinh", 3, 8.5},  // Nhập môn lập trình
       {"MA101", "Toan A1", 4, 7.0},             // Toán A1
       {"MA102", "Toan A2", 3, 8.0},             // Toán A2
       {"PH101", "Vat ly ky thuat", 3, 6.5},     // Vật lý kỹ thuật
       {"EN101", "Anh van", 2, 7.5},             // Anh văn
       7.5                                       // Điểm trung bình tích lũy
    };


    // Hiển thị thông tin sinh viên mẫu
    printf("Ma so sinh vien: %s\n", student.maSoSinhVien);
    printf("Ho ten: %s\n", student.hoTen);
    printf("Diem Nhap mon lap trinh: %.2f\n", student.nhapMonLapTrinh.diem);
    printf("Diem Toan A1: %.2f\n", student.toanA1.diem);
    printf("Diem Toan A2: %.2f\n", student.toanA2.diem);
    printf("Diem Vat ly ky thuat: %.2f\n", student.vatLyKyThuat.diem);
    printf("Diem Anh van: %.2f\n", student.anhVan.diem);
    printf("Diem trung binh: %.2f\n", student.diemTrungBinh);

    return 0;
}
