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
// Hàm tính điểm trung bình tích lũy
float tinhDiemTrungBinh(Student* student) {
    int tongTinChi = student->nhapMonLapTrinh.soTinChi +
        student->toanA1.soTinChi +
        student->toanA2.soTinChi +
        student->vatLyKyThuat.soTinChi +
        student->anhVan.soTinChi;

    float tongDiem = student->nhapMonLapTrinh.diem * student->nhapMonLapTrinh.soTinChi +
        student->toanA1.diem * student->toanA1.soTinChi +
        student->toanA2.diem * student->toanA2.soTinChi +
        student->vatLyKyThuat.diem * student->vatLyKyThuat.soTinChi +
        student->anhVan.diem * student->anhVan.soTinChi;

    return tongDiem / tongTinChi;
}

// Hàm nhập thông tin một môn học
void nhapMonHoc(Subject* subject) {
    printf("Nhap ma mon: ");
    scanf("%s", subject->maMon);
    printf("Nhap ten mon: ");
    scanf(" %[^\n]", subject->tenMon);
    printf("Nhap so tin chi: ");
    scanf("%d", &subject->soTinChi);
    printf("Nhap diem: ");
    scanf("%f", &subject->diem);
}

// Hàm nhập thông tin một sinh viên
void nhapSinhVien(Student* student) {
    printf("Nhap ma so sinh vien: ");
    scanf("%s", student->maSoSinhVien);
    printf("Nhap ho ten sinh vien: ");
    scanf(" %[^\n]", student->hoTen);

    printf("\nNhap thong tin mon Nhap mon lap trinh:\n");
    nhapMonHoc(&student->nhapMonLapTrinh);

    printf("\nNhap thong tin mon Toan A1:\n");
    nhapMonHoc(&student->toanA1);

    printf("\nNhap thong tin mon Toan A2:\n");
    nhapMonHoc(&student->toanA2);

    printf("\nNhap thong tin mon Vat ly ky thuat:\n");
    nhapMonHoc(&student->vatLyKyThuat);

    printf("\nNhap thong tin mon Anh van:\n");
    nhapMonHoc(&student->anhVan);

    // Tính điểm trung bình tích lũy
    student->diemTrungBinh = tinhDiemTrungBinh(student);
}




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
