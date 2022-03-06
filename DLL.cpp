#include<iostream>
using namespace std;

struct Tas{
	string merek, jenis, tipe;
	int harga;
	Tas *prev;
	Tas *next;
	
};

	Tas *head, *tail, *cur, *newNode, *del, *afterNode;
	
	//create Double Linked List
	void createDoubleLinkedList(string merek, string jenis, string tipe, int harga) {
		head = new Tas();
		head->merek = merek;
		head->jenis = jenis;
		head->tipe = tipe;
		head->harga = harga;
		head->prev=NULL;
		head->next=NULL;
		tail = head;
	}
	
		//count Double Linked List
	int countDoubleLinkedList() {
			if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
			} else {
				cur = head;
				int jumlah = 0;
				while (cur != NULL) {
					jumlah++;
				cur= cur->next;
			}
			return jumlah;
		}
	}
	
	//add first Double Linked List
	void addfirst(string merek, string jenis, string tipe, int harga) {
		if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
		} else {
		newNode = new Tas();
		newNode->merek = merek;
		newNode->jenis = jenis;
		newNode->tipe = tipe;
		newNode->harga = harga;
		newNode->prev=NULL;
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
		}
	}
	
	//add last Double Linked List
	void addlast(string merek, string jenis, string tipe, int harga) {
		if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
		} else {
		newNode = new Tas();
		newNode->merek = merek;
		newNode->jenis = jenis;
		newNode->tipe = tipe;
		newNode->harga = harga;
		newNode->prev=tail;
		newNode->next=NULL;
		tail->next=newNode;
		tail=newNode;
		}
	}
	
	//add middle Double Linked List
	void addmiddle(string merek, string jenis, string tipe, int harga, int posisi) {
			if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
		} else {
			if (posisi == 1) {
				cout<<"Posisi 1 itu bukan posisi tengah"<<endl;
			} else if (posisi < 1 || posisi > countDoubleLinkedList() ) {
				cout<<"Posisi diluar jangkauan"<<endl;
			} else {
				newNode = new Tas();
				newNode->merek = merek;
				newNode->jenis = jenis;
				newNode->tipe = tipe;
				newNode->harga = harga;
				newNode->prev=tail;
				newNode->next=NULL;
				
				//tranversing
				cur = head;
				int nomor = 1;
				while (nomor < posisi - 1) {
					cur = cur->next;
					nomor++;
					}
					afterNode = cur->next;
					newNode->prev=cur;
					newNode->next=afterNode;
					cur->next=newNode;
					afterNode->prev=newNode;
			}
		}
	}

		//delete first
	void deletefirst() {
		if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
		} else {
		del=head;
		head=head->next;
		head->prev=NULL;
		delete del;
		}	
	}
	
	//delete last
	void deletelast() {
		if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
		} else {
		del=tail;
		tail=tail->prev;
		tail->next=NULL;
		delete del;
		}	
	}
	
	//delete middle
	void deletemiddle(int posisi) {
		if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
		} else {
			if (posisi ==1 || posisi == countDoubleLinkedList() ) {
				cout<<"Posisi  bukan posisi tengah"<<endl;
			} else if (posisi < 1 || posisi > countDoubleLinkedList() ) {
				cout<<"Posisi diluar jangkauan"<<endl;
			} else {
				int nomor =1;
				cur = head;
				while (nomor < posisi - 1) {
					cur = cur->next;
					nomor++;
				}
				del = cur->next;
				afterNode=del->next;
				cur->next = afterNode;
				afterNode->prev = cur;
				delete del;
			}
		}
	}
	
	//print Double Linked List
	void printDoubleLinkedList() {
			if (head == NULL) {
				cout<<"Double Linked List Belum Dibuat";
			} else {
				cout<<"Jumlah Data : "<<countDoubleLinkedList()<<endl;
				cout<<"Isi Data : "<<endl;
				cur = head;
				while (cur != NULL) {
				cout << "Merek Tas   : "<< cur->merek<<endl;
				cout << "Jenis Tas    : "<< cur->jenis<<endl;
				cout << "Tipe Tas : "<< cur->tipe<<endl;
				cout << "Harga Tas : "<< cur->harga<<endl;
				
				cur= cur->next;
			}
		}
	}

	int main() {
	
	createDoubleLinkedList("Catnip 308", "Tas Kulit", "Tas Selempang", 160000);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	addfirst("Eiger", "Nylon", "Tas Selempang", 275000);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	addlast("Converse", "Kanvas", "Tas Ransel", 500000);
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	addmiddle("Visval Raga", "Polyester Fabric", "Ransel", 350000, 2); //menambahakan data baru di posisi ke-2
	printDoubleLinkedList();
	cout<<"\n\n"<<endl;
	
	/*deletefirst();
	printDoubleLinkedList();
	
	deletelast();
	printDoubleLinkedList();
	
	deletemiddle(3); //menghapus data pada posisi ke-3
	printDoubleLinkedList(); */
	
}
