#include <iostream>
#include <iomanip>// Để sử dụng hàm setw vẽ bảng thao tác
#include <string> 
#include<fstream>  // Thư viện cần thiết để làm việc với file
#include<sstream> // Để sử dụng hàm stringstream ss đọc từng hàng từ tệp txt
#include <cstring>//Thư viện để rfind tìm kiếm tên sinh viên

#include <thread> // Để sử dụng this_thread::sleep_for
#include <chrono> // Để sử dụng std::chrono::seconds
#include <cstdlib>  // Để sử dụng hàm system
// thư viện giúp viết dấu của tiếng việt, thêm thư viện này thì cout phải đổi sang cout
#include <io.h>
#include <fcntl.h>
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
    this_thread::sleep_for(chrono::milliseconds(500));
    ve_ke_ngang(45);
    cout << "|  Lua chon  |           Thao tac           |" << endl;
    ve_ke_ngang(45);
    ve_ke_doc(1, "Them sinh vien");
    ve_ke_ngang(45);
    ve_ke_doc(2, "In danh sach SV");
    ve_ke_ngang(45);
    ve_ke_doc(3, "Sua thong tin SV");
    ve_ke_ngang(45);
    ve_ke_doc(4, "Xoa sinh vien");
    ve_ke_ngang(45);
    ve_ke_doc(5, "Tim kiem SV");
    ve_ke_ngang(45);
    ve_ke_doc(6, "Sap xep danh sach SV");
    ve_ke_ngang(45);
    ve_ke_doc(7, "Thong ke");
    ve_ke_ngang(45);
    ve_ke_doc(8, "Sao Luu du lieu");
    ve_ke_ngang(45);
    ve_ke_doc(9, "Thoat chuong trinh");
    ve_ke_ngang(45);

    cout << endl;
}

// Kiểm tra xem có phải là số hay không n là kiểu int và d là double
void ncheck_so(string loai_cannhap, int giatricannhap)
{
    while (true)
    {

        if (!cin) // or if(cin.fail())
        {
            // user didn't input a number
            cin.clear(); // reset failbit
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
            //di chuyển con trỏ về đầu dòng và ghi đè lên dòng
            //     cout << "\r                        \r";
            // next, request user reinput
            cout << "Nhap "<< loai_cannhap << " lai:";
            cin >> giatricannhap;
        }
        else
        {
            break;
        }
    }
}
void dcheck_so(string loai_cannhap, double giatricannhap)
{
    while (true)
    {

        if (!cin) // or if(cin.fail())
        {
            // user didn't input a number
            cin.clear(); // reset failbit
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
            //di chuyển con trỏ về đầu dòng và ghi đè lên dòng
            //     cout << "\r                        \r";
            // next, request user reinput
            cout << "Nhap " << loai_cannhap << " lai:";
            cin >> giatricannhap;
        }
        else
        {
            break;
        }
    }
}

string string_khongphaichu_in(string &ten)
{
    if (!ten.empty())
    {
        for (size_t i = 0; i < ten.size(); i++)
        {
            if (i == 0 || ten[i - 1] == ' ')
            {
                if (ten[i] >= 'a' && ten[i] <= 'z')
                {
                    ten[i] = ten[i] - 32;
                }
            }
        }
    }
    return ten;
}

bool check_chuoi(const string str)
{
    for (int i = 0; i< str.size();i++)
    {
        if (str[i]>='a' && str[i] <='z' || str[i] >= 'A' && str[i] <= 'Z')
        {
            return true;
        }
    }
    return false;
}
void input_ten_sv(string& ten)
{
    while (true)
    {
        if (check_chuoi(ten)==false)
        {
            // user didn't input a valid string
            std::cin.clear(); // reset failbit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
            std::cout << "\n\tNhap lai ten SV: ";
            std::getline(std::cin, ten);
        }
        else
        {
            break;
        }
    }
}

class Sinhvien
{
private:
    string ten;
    int tuoi,id ;
    double gpa;

public:

    Sinhvien() : ten(""), tuoi(0), id(0), gpa(0.0) {}

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
        
        // Nhập ID
        cout << "Nhap ID: ";
        cin >> id;
        // Nếu ID không phải là số thì sẽ thỏa điều kiện và nhập lại 
        ncheck_so("ID", id);
        
        // Nhập tên
        cout << "\tTen: ";
        cin.ignore();
        getline(cin, ten);
        //check ten
        check_chuoi(ten);
        input_ten_sv(ten);
        // Chuyển đổi chữ cái đầu thành chữ in hoa
        string_khongphaichu_in(ten);

        //Nhâp tuổi
        cout << "\n\tTuoi: ";
        cin >> tuoi;
        ncheck_so("tuoi", tuoi);

        //Nhập GPA
        cout << "\n\tGPA: ";
        cin >> gpa;
        dcheck_so("GPA", gpa);
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
    SV() : next(nullptr) {}
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
        string_khongphaichu_in(tensv);
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

    if (pos < 0 || pos >= n || a == nullptr) return;
    else
    {
        if (pos == 0) //trong danh sách có một phần từ
        {
            sv tmp = a;
            a = a->next;
            delete tmp;
        }
        else
        {
            sv truoc = nullptr, sau = a;
            for (int i = 0; i < pos - 1 && sau != nullptr; i++)
            {
                truoc = sau;
                sau = sau->next;
            }

            // Kiểm tra xem truoc và sau có khác null không trước khi giải tham chiếu
            if (truoc != nullptr && sau != nullptr)
            {
                truoc->next = sau->next;
                delete sau;
            }
        }
    }
}

// in ra thông tin sinh viên
void ve_daukhung()
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
}
void in_danhsach(sv a)
{
    ve_daukhung();

    // Duyệt qua linked list 
    while (a != NULL)
    {
        a->s.in();
        a = a->next;

    }
    ve_ke_ngang(53);
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
void sapxep_ID(sv& a) //sắp xếp sinh viên theo ID tăng dần
{
    for (sv truoc = a; truoc != nullptr; truoc = truoc->next)
    {
        sv min = truoc;
        for (sv sau = truoc->next; sau != nullptr; sau = sau->next)
        {
            if (sau->s.getID() < min->s.getID())
            {
                min = sau;
            }
        }
        Sinhvien tmp = min->s;
        min->s = truoc->s;
        truoc->s = tmp;
    }
}
 //Tìm kiếm trong danh sách

// Tạo một ndoe txt
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
void doc_data_txt(const string& tenfile, sv& a)
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


//Thống kê
void tim_GPA_SV_caonhat(sv a)
{
    sv truoc = a;
    double maxGPA=truoc->s.getGPA();

    sv tmp = truoc;
    bool bien_in_1an = true;

    double biendemSL_SVGPA=0;
    for (sv sau = truoc->next; sau != nullptr; sau = sau->next)
    {
        //so sanh gpa cao nhất
        if (sau->s.getGPA() >= truoc->s.getGPA())
        {
            maxGPA = sau->s.getGPA();
            tmp = sau;
            biendemSL_SVGPA++;

            if (bien_in_1an)
            {
                cout << "Sinh vien co GPA cao nhat: " << maxGPA << endl;;
                ve_daukhung();
                bien_in_1an = false;
            }
            tmp->s.in();
        }
        

    }
    //nếu như không có giá trị lớn hơn thì lấy giá trị đầu là max
    if (biendemSL_SVGPA == 0)
    {
        biendemSL_SVGPA = 1;
        if (bien_in_1an)
        {
            cout << "Sinh vien co GPA cao nhat: " << maxGPA << endl;;
            ve_daukhung();
            bien_in_1an = false;
        }
        tmp->s.in();
    }

    ve_ke_ngang(53);
    

    // tổng số sinh viên
    double tongSV = size(a);

    // tính toán tỷ lệ phần trăm sinh viên có GPA cao nhẩt
    double TLGPA = (biendemSL_SVGPA / tongSV) * 100;
    
    cout << "Ty le SV co GPA cao nhat:" << TLGPA << "%" << endl;;
    cout << endl;
}
void tim_GPA_SV_thapnhat(sv a)
{
    sv truoc = a;

    double minGPA = truoc->s.getGPA();

    sv tmp = truoc;
    bool bien_in_1an = true;

    double biendemSL_SVGPA = 0;

    for (sv sau = truoc->next; sau != nullptr; sau = sau->next)
    {
        //so sanh gpa cao nhất
        if (sau->s.getGPA() <= minGPA)
        {
            minGPA = sau->s.getGPA();
            tmp = sau;
            biendemSL_SVGPA++;

            if (bien_in_1an)
            {
                cout << "Sinh vien co GPA thap nhat: " << minGPA << endl;;
                ve_daukhung();
                bien_in_1an = false;
            }
            tmp->s.in();
        }
        
    }
    //nếu không có giá trị bé nhất thì lấy giá trị đầu
    if (biendemSL_SVGPA == 0)
    {
        biendemSL_SVGPA = 1;
        if (bien_in_1an)
        {
            cout << "Sinh vien co GPA thap nhat: " << minGPA << endl;;
            ve_daukhung();
            bien_in_1an = false;
        }
        tmp->s.in();
    }
    ve_ke_ngang(53);

    // tổng số sinh viên
    double tongSV = size(a);

    // tính toán tỷ lệ phần trăm sinh viên có GPA cao nhẩt
    double TLGPA = (biendemSL_SVGPA / tongSV) * 100;

    cout << "Ty le SV co GPA thap nhat:" << TLGPA << "%" << endl;;
    cout << endl;

}
void diemTB_ALL_lop(sv a)
{
    sv p = a;
    double diemTB_ALL_lop=0;
    while (p != NULL)
    {
        diemTB_ALL_lop = diemTB_ALL_lop + p->s.getGPA();
        p = p->next;
    }

    diemTB_ALL_lop = diemTB_ALL_lop / size(a);
    cout << "Diem trung binh ca lop: " << diemTB_ALL_lop << endl;
}
void phanloaiGPA_SV(sv a)
{
    int demGPA_01 = 0;
    double demGPA_12 = 0;
    double demGPA_23 = 0; 
    double demGPA_34 = 0;

    double TL_01;
    double TL_12;
    double TL_23;
    double TL_34;

    sv p = a;
    while (p != NULL)
    {
        if (0 < p->s.getGPA() && p->s.getGPA()<=1)
        {
            demGPA_01++;
            
        }
        if (1 < p->s.getGPA() && p->s.getGPA() <= 2)
        {
            demGPA_12++;

        }
        if (2 < p->s.getGPA() && p->s.getGPA() <= 3)
        {
            demGPA_23++;

        }
        if (3 < p->s.getGPA() && p->s.getGPA() <= 4)
        {
            demGPA_34++;

        }
        p = p->next;
    }

    double SLSV = size(a);
    TL_01 = demGPA_01 / SLSV * 100;
    TL_12 = demGPA_12 / SLSV * 100;
    TL_23 = demGPA_23 / SLSV * 100;
    TL_34 = demGPA_34 / SLSV *100;

    cout << "Ty le sinh vien GPA <1: " << TL_01 << "%" << endl;
    cout << "Ty le sinh vien GPA >1 và <=2: " << TL_12 << "%" << endl;
    cout << "Ty le sinh vien GPA >2 và <=3: " << TL_23 << "%" << endl;
    cout << "Ty le sinh vien GPA >3 và <=4: " << TL_34 << "%" << endl;

}


// Sao lưu
void luudanhsach(const string& tenfile, sv a)
{
    ofstream data(tenfile, ios::trunc);
    if (data.is_open())
    {
        sv p = a;
        while (p != nullptr)
        {
            data << p->s.getID() << ";" << p->s.getTen() << ";"
                << p->s.getTuoi() << ";" << p->s.getGPA() << endl;
            p = p->next;
        }
        data.close();
        
        //tăng độ trễ 
        cout << "Dang luu";
        for (int i = 0; i < 3; i++)
        {
            cout << ".";
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "\r                             \r";
        cout << endl;
        cout << "Danh sach da duoc luu vao tep thanh cong!" << endl;
    }
    else
    {
        cout << "Khong the mo tep!" << endl;
    }
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
        ncheck_so("vi tri", pos);
        suathongtinDS_SV(head,pos);
    }
    else if (choice == 4) // xóa
    {
        int choice_xoa;
        cout << "Nhap lua chon cach xoa" << endl;
        cout << " 0-Dau\n 1-Cuoi\n 2-Chon\n";
        cin >> choice_xoa;
        ncheck_so("lua chon", choice_xoa);
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
            ncheck_so("vi tri", pos);
            xoa_giua(head, pos);
        }
    }
    else if (choice == 5)// tìm kiếm
    {
        
        //tìm kiếm theo tên
        string tencantim;
        cout << "Nhap ten can tim: ";
        cin.ignore();
        getline(cin, tencantim);
        bool found = false;

        //check found để vẽ
        for (sv p = head; p != NULL; p = p->next)
        {
            if (p->s.getTen().find(tencantim) != string::npos)
            {
                found = true;
            }

        }

        //điều kiện để vẽ khung
        if (found)
        {
            ve_daukhung();
        }
        
        //TÌM TÊN
        for (sv p = head; p != NULL; p = p->next)
        {
            if (p->s.getTen().find(tencantim) != string::npos)
            {
                p->s.in();             
            }

        }

        if (!found)
        {
            cout << "Khong tim thay ten trong danh sach." << endl;
        }
        ve_ke_ngang(53);
        cout << endl;
        //tím kiếm theo tuổi
        //tìm kiếm theo GPA
    } 
    else if (choice == 6) //sắp xếp
    {
        int choice_xoa;
        cout << "Lua chon cach sap xep" << endl;
        cout << " 0-GPA\n 1-tuoi\n 2-ID\n";
        cout << "Nhap: ";
        cin >> choice_xoa;
        ncheck_so("lua chon",choice_xoa);

        if (choice_xoa == 0) //GPA
        {
            sapxep_gpa(head);

        }
        else if (choice_xoa == 1) //tuoi
        {
            sapxep_tuoi(head);
        }
        else if (choice_xoa == 2) //ID
        {
            sapxep_ID(head);
        }
    }
    else if (choice == 7) // thống kê
    {
            //sinh viên-tỷ lệ có GPA cao nhất
            tim_GPA_SV_caonhat(head);
            //sinh viên-tỷ lệ GPA thấp nhất
            tim_GPA_SV_thapnhat(head);
            
            //Điểm trung bình cả lớp
            diemTB_ALL_lop(head);
            
            ////Tỷ lệ giứa các GPA
            phanloaiGPA_SV(head);

    }
    else if (choice == 8)// sao lưu
    {
        luudanhsach("data.txt", head);
    }
    else if (choice == 9)
    {
        thoat = false;
        cout << "Ket thuc chuong trinh!" << endl;
    }
    else
    {
        cout << "Nhap lai lua chon: ";
        cin >> choice;
        luachon(choice,head, thoat);
        
    }
}


int main()
{
    

    sv head = nullptr;
    int choice = 0;
    bool thoat = true;
    doc_data_txt("data.txt", head);
    

    
    cout << "Dang tai du lieu len!";
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "Hoan Thanh";
    this_thread::sleep_for(chrono::seconds(1));
    system("cls");



    while (thoat)
    { 
        bang(); 
        cout << "Nhap luc chon: ";
        cin >> choice;
        luachon(choice, head, thoat);
        this_thread::sleep_for(chrono::seconds(1));

    }
    return 0;
}
