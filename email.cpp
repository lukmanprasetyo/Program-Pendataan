//Belajar buat database

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Email {
	public:
		string Nama;
		string email;
		string Wa;
		string Ig;

		Email(string Nama, string email, string Wa, string Ig){
			Email::Nama = Nama;
			Email::email = email;
			Email::Wa = Wa;
			Email::Ig = Ig;
		}

		string stringfly(){
			return "\n" + Nama + " " + email + " " + Wa + " " + Ig + "";
		}

};

class DBase{
	public:
		ifstream in;
		ofstream out;
		string filename;

		DBase(const char* filename){
			DBase::filename = filename;
		}

		void save (Email data){
			cout << data.Nama << endl;
			cout << data.email << endl;
			cout << data.Wa << endl;
			cout << data.Ig << endl;

			DBase::out.open(DBase::filename,ios::app);
			DBase::out << data.stringfly();
			DBase::out.close();
		}

		void showAll(){
			DBase::in.open(DBase::filename,ios::in);
			string Nama,email,Wa,Ig;
			int index = 1;

			while (!DBase::in.eof()){
				DBase::in >>Nama;
				DBase::in >>email;
				DBase::in >>Wa;
				DBase::in >>Ig;
				cout << index++ << ".\t";
				cout << Nama << "\t";
				cout << email << "\t";
				cout << Wa << "\t";
				cout << Ig << endl;
				
			}

			DBase::in.close();
		}
};

int main (){

	//Membuat object yang di perlukan
	DBase database = DBase("email.txt");
	//database.showAll();

	//input name
	string Nama,email,Wa,Ig;
    cout << " Program Save Email \n" << endl;
	
	cout << "Masukkan Nama 	= ";
	cin>> Nama;
	cout << " Email 		= ";
	cin >> email;
	cout << " Nomor Hp/Wa 	= ";
	cin >>Wa;
	cout << " Nama Ig 	= ";
	cin >> Ig;


	Email dataEmail = Email (Nama,email,Wa,Ig);

	//save data ke database
	database.save(dataEmail);

	//Tampilkan seluruh data mahasiswa
	database.showAll();

	return 0;
}