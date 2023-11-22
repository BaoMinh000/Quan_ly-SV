#include<iostream>
#include<fstream>  // Thư viện cần thiết để làm việc với file
#include<string> // Để dùng string 
#include<sstream> // Để sử dụng hàm stringstream ss đọc từng hàng từ tệp txt
#include <cstdlib> // Để sử dụng hàm system
#include <iomanip> // Để sử dụng hàm setw vẽ bảng thao tác

using namespace std;

//khai báo hàm 
void ve_ke_ngang(int chieu_rong);
void ve_ke_doc(int lua_chon, const string& thao_tac);
void bang_thao_tac();

class SinhVien
{
private:
	int masv;
	string ten;
	int tuoi;
	double gpa;

public:
	// Constructor with default values
	SinhVien(int m = 0, const string& t = "", int age = 0, double g = 0.0) : masv(m), ten(t), tuoi(age), gpa(g) {}

	// Member function to input student information
	void nhap()
	{
		cout << "[2] Them sinh vien:" << endl;
		cout << "\tTen: ";
		cin.ignore();
		getline(cin, ten);
		cout << "\n\tTuoi: ";
		cin >> tuoi;
		cout << "\n\tGPA: ";
		cin >> gpa;
	}

	//In ra thông tin sinh viên
	void hienThi() const 
	{
		// khai báo ép kiểu để tránh bị thông báo tràng bộ nhớ
		size_t tenWedth_left = ten.length() + 3;
		size_t tenWedth_right = 30 - ten.length();

		//Vẽ bảng tên, tuôi, gpa của sinh viên
		cout << "|" << setw(tenWedth_left) << ten << setw(tenWedth_right) << "|"
			 << setw(4) << tuoi << setw(5) << "|"
		   	 << setw(7) << fixed << setprecision(2)  << gpa << setw(3) << "|" << endl;
	}
	void inSV(const string& tenfile) 
	{
		//Xác thực file có được mở hay không 
		ifstream filtest(tenfile);
		if (filtest.fail())
		{
			cout << "Khong the mo tep!" << endl;
			return;
		}

		string line;

		while (getline(filtest, line))
		{
			stringstream ss(line);

			getline(ss, ten, ';');
			ss >> tuoi;
			ss.ignore();//bỏ qua một ký tự là dấu ;
			ss >> gpa;

			hienThi();  // Hiển thị thông tin sinh viên
		}

		filtest.close();
	}

	// Member function to write student information to a file
	void ghiVaoTep(const string& tenfile) const
	{
		ofstream filtest(tenfile, ios::app);
		//check file
		if (!filtest.is_open()) {
			cout << "Khong the mo tep! ";
			return;
		}

		filtest << ten << ";" << tuoi << ";" << gpa << endl;
		filtest.close();
	}

	// Getter functions for accessing private members
	int getMaSV() const {
		return masv;
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
	void setMaSV(int m) {
		masv = m;
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
};

//######################################################### Hàm chức năng
// In thông tin sinh viên
void inSV(SinhVien& sinhvien, const string tenfile)
{
	//hiển thị header
	string header_tenSV = "Ten sinh vien";
	string header_tuoiSV = "Tuoi";
	string header_gpaSV = "GPA";

	// khai báo ép kiểu để tránh bị thông báo tràng bộ nhớ
	size_t tenWidth = header_tenSV.size() + 8;
	size_t tuoiWidth = header_tuoiSV.size() + 2;
	size_t gpaWidth = header_gpaSV.size() + 3;

	//vẽ
	ve_ke_ngang(53);
	cout << "|" << setw(tenWidth) << header_tenSV << setw(12) << "|"
		 << setw(tuoiWidth) << header_tuoiSV << setw(3) << "|"
		 << setw(gpaWidth) << header_gpaSV << setw(4) << "|" << endl;
	ve_ke_ngang(53);

	//gọi hàm void in từ class public
	sinhvien.inSV(tenfile);
}
// Hàm để thêm sinh viên vào tệp
void themSV(const SinhVien& sinhvien, const string& tenfile)
{
	sinhvien.ghiVaoTep(tenfile);
}
//Xóa sinh viên trong linked list
void xoaSV(const string& tenfile)
{

	


}

//######################################################### Hàm lựa chọn chức năng
void thao_tac(int choice, bool &thoat)
{
	SinhVien sv;
	switch (choice) 
	{
		case 1:
		{
			inSV(sv, "my_testfile.txt");
			break;

		}
		case 2:
		{
		
			SinhVien newsinhvien;
			newsinhvien.nhap();  // Input information for the new student
			themSV(newsinhvien, "my_testfile.txt");
			break;
		}
		case 3:
		{
			// xóa đối 1 sinh viên
		}
		// Thêm các trường hợp khác nếu cần
		case 9:
		{
			thoat = false; // Kết thúc chương trình
			break;
		}
		
		default:cout << "Lenh khong hop le\n";
	}

}


int main()
{
	//Biến chọn trong bảng thao tác
	int choice;
	// Biến logic để thoát bảng thao tác
	bool thoat = true;

	while(thoat)
	{
		bang_thao_tac();
		
		cout << "Nhap lenh: ";
		cin >> choice;

		thao_tac(choice, thoat);

		//Dừng màn hình
		system("pause");
		// Làm sạch màn hình console
		system("cls");

	}
	return 0;
}


void ve_ke_ngang(int chieu_rong)
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
		 << setw(thaoTacWidth_right)<< "|" << endl;
}
void bang_thao_tac()
{
	ve_ke_ngang(45);
	// In tiêu đề bảng thao tác
	cout << setw(30) << "BANG THAO TAC" << endl;

	ve_ke_ngang(45);
	cout << "|  Lua chon  |           Thao tac           |" << endl;
	ve_ke_ngang(45);
	ve_ke_doc(1, "In danh sach SV");
	ve_ke_ngang(45);
	ve_ke_doc(2, "Them sinh vien");
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
}

//void kiemtra_user_created_newfile()
//{
//	int choice_file = 0;
//	cout << "Ban co muon tao file moi khong: " << endl;
//	cout << "1-Yes  \n2-No\n";
//	cout << "Nhap: ";
//	cin >> choice_file;
//
//	if (choice_file == 1)
//	{
//		// Create a new file
//		ofstream newFile("data_quanlySV.txt");
//		// Check if the new file is created successfully
//		if (!newFile.is_open())
//		{
//			cout << "Error creating a new file." << endl;
//		}
//		else cout << "File created suscessfully \n";
//	}
//	else if (choice_file == 2)
//	{
//		return;
//	}
//}

