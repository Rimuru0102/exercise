#include<bits/stdc++.h>
using namespace std;
class sinhvien{
	public:
	int id;
	string name;
	string email;
	string phone;
	int bill;
};

void doc_file_data(ifstream &Filein, sinhvien &sv){
  string id,bill,phone;
  getline(Filein, id);
  getline(Filein, sv.name);
  getline(Filein, sv.email);
  getline(Filein, sv.phone);
  getline(Filein, bill);
  sv.id = atoi(id.c_str());
  sv.bill = atoi(bill.c_str());
}

void Tim_kiem_sinh_vien_theo_ten(sinhvien arr[100], int n){
	string ten;
	cout << "Nhap ten:";
	getline(cin,ten);
	for(int i=0; i<ten.size(); i++){
		if((ten[i]>='A') && (ten[i]<='Z') ){
			ten[i]+=32;
		}
	}
	
	for(int i=0;i<n;i++){
		string check;
		check = arr[i].name;
		for(int j=0; j<check.size(); j++){
			if((check[j]>='A')&&(check[j]<='Z')){
				check[j]+=32;
			}
		}
		if(check.compare(ten) == 0){
			cout << "------------------------------\n";
			cout << "id: " << arr[i].id << endl;
			cout << "name: " << arr[i].name << endl;
			cout << "email: " << arr[i].email << endl;
			cout << "phone: " << arr[i].phone << endl;
			cout << "bill: " << arr[i].bill << endl;
		}
	}
}

int main(){
	ifstream Filein;
	Filein.open("C:\\Users\\Nguyen Phuong Dung\\Documents\\Data.txt", ios_base::in);
	ofstream Fileout;
	Fileout.open("C:\\Users\\Nguyen Phuong Dung\\Documents\\Output.txt",ios_base::out);
	sinhvien arr[100];
	sinhvien x;
	int dem=0;
	int i;
	int m;
	while(Filein.eof() == false){
		string y;
		getline(Filein,y);
		dem++;
	}
	int n = dem/5;
	Filein.seekg(0,ios_base::beg);
	for(i=0;i<n;i++){
		doc_file_data(Filein, x);
		arr[i]=x;
	}
	Fileout << left <<setw(20)<<"Id"<<setw(30)<<"Name"<<setw(30)<<"Email"<<setw(20)<<"Phone"<<setw(20)<<"Bill"<<endl;
	for(i=0; i<n; i++){
		Fileout << left <<setw(20)<<arr[i].id<<setw(30)<<arr[i].name<<setw(30)<<arr[i].email<<setw(20)<<arr[i].phone<<setw(20)<<arr[i].bill<<endl;
	}
	cout << "Menu:" << endl;
	cout << "1.Xem thong tin tat ca sinh vien" << endl;
	cout << "2.Tim_kiem_sinh_vien_theo_ten" << endl;
	cout << "3.Ket thuc chuong trinh" << endl;
	cout << "Chon chuc nang: ";
	while(1){
	cin >> m;
	cin.ignore();
	switch(m){
		case 1:
			cout << left <<setw(20)<<"Id"<<setw(30)<<"Name"<<setw(30)<<"Email"<<setw(20)<<"Phone"<<setw(20)<<"Bill"<<endl;
			for(i=0;i<n;i++){
		        cout << left <<setw(20)<<arr[i].id<<setw(30)<<arr[i].name<<setw(30)<<arr[i].email<<setw(20)<<arr[i].phone<<setw(20)<<arr[i].bill<<endl;
	        }
	        break;
	    case 2:
	    	Tim_kiem_sinh_vien_theo_ten(arr,n);
	    	break;
	    case 3:
	    	return 1;
	    default:
	        break;
	}
	Filein.close();
	Fileout.close();
	return 0;
  }
}
