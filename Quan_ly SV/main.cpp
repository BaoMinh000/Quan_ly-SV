#include <iostream>
#include <iomanip>
#include <string>
#include<fstream>  // Thư viện cần thiết để làm việc với file
#include <stdexcept>
#include<sstream> // Để sử dụng hàm stringstream ss đọc từng hàng từ tệp txt


using namespace std;

void ve_ke_ngang(int chieu_rong )
{
    for (int i = 0; i < chieu_rong; i++)
    {
        cout << "-";
    }
    cout << endl;
}
void ve_ke_doc(int lua_chon, const string& thao_tac)
{
    // khai báo ép kiểu để tránh bị thông báo tràng bộ nhớ
    size_t thaoTacWidth_left = thao_tac.size() + 5;
    size_t thaoTacWidth_right = 26 - thao_tac.size();

    //vẽ bảng theo lua chon và thao tac
    cout << "|" << setw(6) << lua_chon << setw(7) << "|"
        << setw(thaoTacWidth_left) << thao_tac
        << setw(thaoTacWidth_right) << "|" << endl;
}

void bang()
{
    ve_ke_ngang(45);
    // In tiêu đề bảng thao tác
    cout << setw(30) << "BANG THAO TAC" << endl;

    ve_ke_ngang(45);
    cout << "|  Lua chon  |           Thao tac           |" << endl;
    ve_ke_ngang(45);
    ve_ke_doc(1, "Them sinh vien");
    ve_ke_ngang(45);
    ve_ke_doc(2, "In danh sach SV");
    ve_ke_ngang(45);
    ve_ke_doc(3, "Sua thong tin SV");//
    ve_ke_ngang(45);
    ve_ke_doc(4, "Xoa sinh vien");
    ve_ke_ngang(45);
    ve_ke_doc(5, "Tim kiem SV");
    ve_ke_ngang(45);
    ve_ke_doc(6, "Sap xep danh sach SV");
    ve_ke_ngang(45);
    ve_ke_doc(7, "Thong ke");//
    ve_ke_ngang(45);
    ve_ke_doc(8, "Sao Luu du lieu");//
    ve_ke_ngang(45);
    ve_ke_doc(9, "Thoat chuong trinh");
    ve_ke_ngang(45);

    for (int i = 0; i < 29; i++)
    {
        cout << "-";
    }
    cout << endl;
}

class Sinhvien
{
private:
    string ten;
    int tuoi,id ;
    double gpa;

public:

    
    // Getter functions for accessing private members
    int getID() const {
        return id;
    }
    string getTen() const {
        return ten;
    }
    int getTuoi() const {
        return tuoi;
    }
    double getGPA() const {
        return gpa;
    }

    // Setter functions for modifying private members
    void setID(int m) {
        this->id = m;
    }
    void setTen(const string& t) {
        ten = t;
    }
    void setTuoi(int age) {
        tuoi = age;
    }
    void setGPA(double g) {
        gpa = g;
    }

    void nhap()
    {
        cout << "[2] Them sinh vien:" << endl;
        cout << "Nhap ID: ";
        cin >> id;
        cout << "\tTen: ";
        cin.ignore();
        getline(cin, ten);
        cout << "\n\tTuoi: ";
        cin >> tuoi;
        cout << "\n\tGPA: ";
        cin >> gpa;
    }

    void in() // in 1 sinh viên
    {

        // khai báo ép kiểu để tránh bị thông báo tràng bộ nhớ
        size_t tenWedth_left_ten = ten.length() + 3;
        size_t tenWedth_right_ten = 23 - ten.length();

        //Vẽ và in bảng id, tên, tuôi, gpa của sinh viên
        cout<< "|"<< setw(5)<<id <<setw(2)
            << "|" << setw(tenWedth_left_ten) << ten << setw(tenWedth_right_ten) << "|"
            << setw(4) << tuoi << setw(5) << "|"
            << setw(7) << fixed << setprecision(2) << gpa << setw(3) << "|" << endl;
    }


};

struct SV //node
{
    Sinhvien s;
    SV* next;

};

typedef struct SV* sv;


// Tạo một ndoe 
sv create_node()
{
    sv tmp = new SV();
    tmp->s.nhap();
    tmp->next = nullptr;
    return tmp;
}


// check rỗng
bool empty(sv a)
{
    return a == NULL;
}

//check sise
int size(sv a)
{
    int count = 0;
    while (a != NULL)
    {
        count++;
        a = a->next;
    }
    return count;
}

// Thêm một phàn từ vào đầu danh sách liên kết
void them_dau(sv& a)
{
    sv tmp = create_node();
    if (a == NULL)
    {
        a = tmp;
    }
    else
    {
        tmp->next = a;
        a = tmp;
    }
}
//Thêm một phần từ vào cuối danh sách
void them_cuoi(sv& a)
{
    sv tmp = create_node();

    if (a == NULL)
    {
        a = tmp;
    }
    else
    {
        sv p = a;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
}

// Sửa thông tin 1 sinh viên
void suathongtin(sv& a)
{
    int choice_thongtin;

    cout << "Chon thong tin can sua: " << endl;
    cout << "1-Ten\n2-GPA\n3-Tuoi" << endl;
    cout << "Nhap lua chon: ";
    cin >> choice_thongtin;

    if (choice_thongtin == 1) //ten
    {
        string tensv = "";
        cout << "Nhap ten sinh vien: ";
        cin.ignore();
        getline(cin,tensv);
        a->s.setTen(tensv);
        cout << endl;

    }
    else if (choice_thongtin == 2) // gpa
    {
        int gpasv;
        cout << "Nhap gpa sinh vien: ";
        cin >> gpasv;
        a->s.setGPA(gpasv);
        cout << endl;
    }
    else if (choice_thongtin == 3) // tuoi
    {
        int tuoisv;
        cout << "Nhap tuoi sinh vien: ";
        cin >> tuoisv;
        a->s.setTuoi(tuoisv);
        cout << endl;
    }

}
// Sửa thông tin trong danh sách sinh viên 
void suathongtinDS_SV(sv& a, int  pos)
{
    int n = size(a);

    if (pos <= 0 || pos > n)
    {
        cout << "Vi tri khong hop le!";
        return;
    }
    else
    {
        // Duyệt đến vị trí pos
        sv p = a;
        for (int i = 1; i < pos; i++)
        {
            p = p->next;
        }
        suathongtin(p);
    }
}

//Xóa 1 sinh viên
// Xóa node đầu
void xoa_dau(sv& a)
{
    if (a != NULL)
    {
        sv tmp = a;
        a = a->next;
        delete tmp;
    }


}
//Xóa phần tử ở cuối
void xoa_cuoi(sv& a)
{
    if (a != nullptr)
    {
        sv truoc = nullptr, sau = a;

        // Duyệt đến cuối danh sách
        while (sau->next != nullptr)
        {
            truoc = sau;
            sau = sau->next;
        }

        // Kiểm tra danh sách có nhiều hơn 1 phần tử hay không
        if (truoc == nullptr)
        {  // Danh sách chỉ có một phần tử
            delete a;
            a = nullptr;
        }
        else
        {  // Danh sách có nhiều hơn 1 phần tử
            delete sau;
            truoc->next = nullptr;
        }
    }
}
//xóa giữa
void xoa_giua(sv& a, int pos)
{
    int n = size(a);

    if (pos < 0 || pos > n) return;
    sv truoc = nullptr, sau = a;

    for (int i = 0; i < pos - 1; i++)
    {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == nullptr) //trong danh sách có một phần từ
    {
        sv tmp = a;
        a = a->next;
        delete tmp;
    }
    else
    {
        truoc->next = sau->next;
        delete sau;

    }
}

// in ra thông tin sinh viên
void in_danhsach(sv a)
{
    //Hiển thị header
    string header_idSV = "STT";
    string header_tenSV = "Ten sinh vien";
    string header_tuoiSV = "Tuoi";
    string header_gpaSV = "GPA";

    // khai báo ép kiểu để tránh bị thông báo tràng bộ nhớ
    size_t idwidth = header_idSV.size() + 2;
    size_t tenWidth = header_tenSV.size() + 6;
    size_t tuoiWidth = header_tuoiSV.size() + 2;
    size_t gpaWidth = header_gpaSV.size() + 3;

    //vẽ header
    ve_ke_ngang(53);
    cout << "|" << setw(idwidth) << header_idSV << setw(2)
         << "|" << setw(tenWidth) << header_tenSV << setw(7) << "|"
         << setw(tuoiWidth) << header_tuoiSV << setw(3) << "|"
         << setw(gpaWidth) << header_gpaSV << setw(4) << "|" << endl;
    ve_ke_ngang(53);

    // Duyệt qua linked list 
    while (a != NULL)
    {
        a->s.in();
        a = a->next;

    }
    cout << endl;

}

//sắp xếp danh sách sinh viên
void sapxep_gpa(sv& a) //sắp xếp sinh viên theo gpa tăng dần
{
    for (sv truoc = a; truoc != nullptr; truoc = truoc->next)
    {
        sv min = truoc;
        for (sv sau = truoc->next; sau != nullptr; sau = sau->next)
        {
            if (sau->s.getGPA() < min->s.getGPA())
            {
                min = sau;
            }
        }
        // Đổi chỗ con trỏ nút, không phải giá trị dữ liệu trực tiếp
        Sinhvien tmp = min->s;
        min->s = truoc->s;
        truoc->s = tmp;
    }
}
void sapxep_tuoi(sv& a) //sắp xếp sinh viên theo tuổi tăng dần
{
    for (sv truoc = a; truoc != nullptr; truoc = truoc->next)
    {
        sv min = truoc;
        for (sv sau = truoc->next; sau != nullptr; sau = sau->next)
        {
            if (sau->s. getTuoi() < min->s.getTuoi())
            {
                min = sau;
            }
        }
        // Đổi chỗ con trỏ nút, không phải giá trị dữ liệu trực tiếp
        Sinhvien tmp = min->s;
        min->s = truoc->s;
        truoc->s = tmp;
    }
}

// Tìm kiếm trong danh sách

// Lưu
void luu_1SV(const string& tenfile, sv &a )
{
    ofstream data(tenfile, ios::app);
    //check file
    if (!data.is_open())
    {

        data << a->s.getID() << ";" << a->s.getTen() << ";"
             << a->s.getTuoi() << ";" << a->s.getGPA() << endl;
        data.close();

        cout << "File da duoc luu thanh cong!" << endl;
    }
    else
    {
        cout << "Khong the tao file!" << endl;
    }

   
}
void luudanhsach(const string& tenfile,sv a)
{
    sv p = a;
    while (p != NULL)
    {
        luu_1SV(tenfile, p);
        p = p->next;

    }
}

// Tạo một ndoe 
sv create_node_txt()
{
    sv tmp = new SV();
    tmp->s = Sinhvien();
    tmp->next = nullptr;
    return tmp;
}

// đọc dữ liệu từ txt
void themcuoi_txt(sv& a, const Sinhvien& sv_tmp)
{
    sv tmp = create_node_txt();
    tmp->s = sv_tmp;

    if (a == NULL)
    {
        a = tmp;
    }
    else
    {
        sv p = a;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
}
void doc_data_txt(const string &tenfile, sv& a)
{
    ifstream filtest(tenfile);
    if (filtest.fail())
    {
        cout << "Khong the mo tep!" << endl;
    }
    else
    {
        string line;

        int id, tuoi;
        string name;
        double gpa;

        while (getline(filtest, line))
        {
            stringstream ss(line);

            // Tạo một đối tượng Sinhvien mới để lưu dữ liệu từ file
            Sinhvien sv_tmp;

            ss >> id;
            sv_tmp.setID(id);
            ss.ignore();
            getline(ss, name, ';');
            sv_tmp.setTen(name);
            ss.ignore();
            ss >> tuoi;
            sv_tmp.setTuoi(tuoi);
            ss.ignore();
            ss >> gpa;
            sv_tmp.setGPA(gpa);

            // Thêm sinh viên mới vào danh sách
            themcuoi_txt(a, sv_tmp);
        }
    }

    filtest.close();
}

void luachon(int& choice, sv& head, bool &thoat)
{

    if (choice == 1)// thêm (vị trí cuối)
    {

        them_cuoi(head);
    }
    else if (choice == 2) // in ra sinh vien
    {
        in_danhsach(head);
    }
    else if (choice == 3) // sửa thông tin sv
    {
        int pos;
        cout << "Nhap vi tri can chen: ";
        cin >> pos;
        suathongtinDS_SV(head,pos);
    }
    else if (choice == 4) // xóa
    {
        int choice_xoa;
        cout << "Nhap lua chon cach xoa" << endl;
        cout << " 0-Dau\n 1-Cuoi\n 2-Chon\n";
        cin >> choice_xoa;
        if (choice_xoa == 0) // xóa đầu
        {
            xoa_dau(head);
        }
        else if (choice_xoa == 1) // xóa cuối
        {
            xoa_cuoi(head);
        }
        else if (choice_xoa == 2) // chọn vị trí xóa 
        {
            int pos;
            cout << "Nhap vi tri can xoa: ";
            cin >> pos;
            xoa_giua(head, pos);
        }
    }
    else if (choice == 5)
    {

    }
    else if (choice == 6) //sắp xếp
    {
        int choice_xoa;
        cout << "Lua chon cach sap xep" << endl;
        cout << " 0-GPA\n 1-Ten\n 2-Tuoi\n 3-ID\n";
        cout << "Nhap: ";
        cin >> choice_xoa;
        if (choice_xoa == 0) 
        {
            sapxep_gpa(head);

        }
        else if (choice_xoa == 1)
        {
            sapxep_tuoi(head);
        }
        else if (choice_xoa == 2)
        {

        }
        else if (choice_xoa == 3)
        {

        }
    }
    else if (choice == 7) // thống kê
    {

    }
    else if (choice == 8)// sao lưu
    {
        luudanhsach("data", head);
    }
    else if (choice == 9)
    {
        thoat = false;
        cout << "Ket thuc chuong trinh!" << endl;
    }
}

int main()
{

    sv head = nullptr;    

    int choice = 0;
    bool thoat = true;

    doc_data_txt("data.txt", head);

    while (thoat)
    { 
        bang();
        cout << "Nhap luc chon: ";
        cin >> choice;
        luachon(choice, head,thoat);
    }
    return 0;
}
