#include"Header.h"

void createPetData(PET &petData)
{

	string listColor[5] = { "vang", "nau", "trang", "den", "xam" };

	do
	{
		cout << "Nhap ma thu cung: ";
		cin >> petData.petID;
		if (petData.petID.length() != 7)
			cout << "Nhap ma thu cung khong phu hop, Ma thu cung phai la 7, vui long nhap lai!" << endl;
	} while (petData.petID.length() != 7);

	cin.ignore();
	do
	{
		cout << "Nhap ten thu cung: ";
		getline(cin, petData.petName);
		if (petData.petName.length() > 30)
			cout << "Nhap ten thu cung vuot qua do dai cho phep, vui long nhap lai!" << endl;
	} while (petData.petID.length() > 30);

	do
	{
		cout << "Nhap can nang thu cung: ";
		cin >> petData.petWeight;
		if (petData.petWeight < 0)
			cout << "Nhap can nang thu cung khong phu hop, vui long nhap lai!" << endl;
	} while (petData.petWeight < 0);

	do
	{
		cout << "Nhap tuoi thu cung: ";
		cin >> petData.petAge;
		if (petData.petAge < 0)
			cout << "Nhap tuoi thu cung khong phu hop, vui long nhap lai!" << endl;
	} while (petData.petAge < 0);

	do
	{
		cout << "Nhap mau thu cung: ";
		cin >> petData.petColor;
		if (find(begin(listColor), end(listColor), petData.petColor) == end(listColor))
		{
			cout << "Nhap mau thu cung khong hop le, vui long nhap lai!" << endl;
			cout << "5 mau sac hop le la vang, nau, trang, den, xam! " << endl;
		}

	} while (find(begin(listColor), end(listColor), petData.petColor) == end(listColor));

}

void printPetData(PET petData)
{
	cout << "Thu cung ma so: ";
	cout << petData.petID << endl;
	cout << "Ten thu cung: ";
	cout << petData.petName << endl;
	cout << "Tuoi thu cung: ";
	cout << petData.petAge << endl;
	cout << "Can nang thu cung: ";
	cout << petData.petWeight << endl;
	cout << "Mau sac thu cung: ";
	cout << petData.petColor << endl;
}

void initPetStore(PetStore &psName)
{
	psName.head = NULL;
	psName.tail = NULL;
}

bool isEmptyPetStore(PetStore &psName)
{
	if (psName.head == NULL)
		return true;
	else
		return false;
}

Node *createPetNode(PET petDataInput)
{
	Node *newNode = new Node;
	if (newNode == NULL)
	{
		cout << "Khong du bo nho de cap phat bo nho cho thong tin pet!" << endl;
		return NULL;
	}
	newNode->petData = petDataInput;
	newNode->next = NULL;
	return newNode;
}

Node* findPetByID(PetStore &psName, string findingPetID)
{
	Node* currentNode = psName.head;
	while (currentNode != NULL)
	{
		if (currentNode->petData.petID == findingPetID)
		{
			return currentNode;
		}
		else
		{
			currentNode = currentNode->next;
		}
	}
	return NULL;
}


void addPetAtHead(PetStore &psName, Node *nodeAdded)
{
	if (psName.head == NULL)
	{
		psName.head = nodeAdded;
		psName.tail = nodeAdded;
	}
	else
	{
		nodeAdded->next = psName.head;
		psName.head = nodeAdded;
	}
}

void addPetAtTail(PetStore &psName, Node* nodeAdded)
{
	if (psName.head == NULL)
	{
		addPetAtHead(psName, nodeAdded);
	}
	else
	{
		psName.tail->next = nodeAdded;
		psName.tail = nodeAdded;
	}
}


void addPetAfterPetID(PetStore &psName, string afterID, Node* nodeAdded)
{
	Node *nodeFound = findPetByID(psName, afterID);
	if (nodeFound != NULL)
	{
		Node* temp = nodeFound->next;

		nodeFound->next = nodeAdded;
		nodeAdded->next = temp;
	}
	else
	{
		cout << "Do khong tim thay ma pet can add nen se add vao duoi!" << endl;
		addPetAtTail(psName, nodeAdded);
	}
}

void initPetStoreFunction(PetStore &psName)
{
	cout << "Cua hang da duoc tu khoi tao san nen cua hang se duoc reset!" << endl;
	initPetStore(psName);
	cout << "Da khoi Lai tao pet store!" << endl;

}


void addPetAfterIdFunction(PetStore &psName)
{
	PET pet;
	string idPetAddedAfter;
	cout << "Nhap thong tin pet: " << endl;
	createPetData(pet);
	Node *newPet = createPetNode(pet);
	if (psName.head == NULL)
	{
		cout << "Vi danh sach rong nen thong tin pet vua add se duoc them vao dau!" << endl;
		addPetAtHead(psName, newPet);
	}
	else
	{
		cout << "Ban muon add sau ma pet nao?: ";
		cin >> idPetAddedAfter;
		addPetAfterPetID(psName, idPetAddedAfter, newPet);
	}
}

void addPetFunction(PetStore &psName)
{
	PET petN;
	createPetData(petN);
	Node *newPet = createPetNode(petN);
	Node *petFound = findPetByID(psName, newPet->petData.petID);
	if (petFound == NULL)
	{
		if (psName.head == NULL)
		{
			addPetAtHead(psName, newPet);
		}
		else
		{
			addPetAtTail(psName, newPet);
		}
		cout << "Hoan thanh them thong tin pet vao cua hang!" << endl;
	}
	else
	{
		cout << "Thong tin pet nhap vao da ton tai, ";
		cout << "vui long kiem tra lai thong tin pet!" << endl;;
	}

}

void delPetAtHead(PetStore &psName)
{

	if (psName.head != NULL)
	{
		Node *nodeCurr = psName.head;
		psName.head = psName.head->next;

		delete nodeCurr;
	}
	else
	{
		psName.head = psName.tail = NULL;
		cout << "List khong ton tai phan tu nao!";
	}
}

void delPetAtTail(PetStore &psName)
{
	if (psName.tail != NULL)
	{
		Node *nodeCur = psName.head;
		Node *nodeTail = psName.tail;
		while (nodeCur->next != psName.tail)
		{
			nodeCur = nodeCur->next;
		}

		psName.tail = nodeCur;
		nodeCur->next = NULL;

		delete nodeTail;
	}
	else
	{
		delPetAtHead(psName);
	}
}

void delPetByID(PetStore &psName, string afterID)
{
	Node* nodeAfter = findPetByID(psName, afterID);
	if (nodeAfter == psName.head)
	{
		delPetAtHead(psName);
	}
	else if (nodeAfter == psName.tail)
	{
		delPetAtTail(psName);
	}
	else
	{
		Node *nodeCur = psName.head;
		while (nodeCur->next != nodeAfter)
		{
			nodeCur = nodeCur->next;
		}
		nodeCur->next = nodeAfter->next;

		delete nodeAfter;
	}
}

void delPetByWeight(PetStore &psName)
{
	PET pet;
	float petWeightDel;
	int countPetDel = 0;
	cout << "Xoa thong nhung pet co can nang lon hon: ";
	cin >> petWeightDel;

	Node* nodeCur = psName.head;
	Node* prev = NULL;
	while (nodeCur != NULL)
	{
		if (nodeCur->petData.petWeight > petWeightDel)
		{
			if (nodeCur == psName.head) {
				delPetAtHead(psName);
				nodeCur = psName.head;
				continue;
			}
			if (nodeCur == psName.tail) {
				delPetAtTail(psName);
				psName.tail = prev;
				break;
			}
			delete nodeCur;
			nodeCur = prev->next;
		}
		else
		{
			prev = nodeCur;
			nodeCur = nodeCur->next;
		}
	}
	cout << "Hoan thanh xoa pet " << endl;
}

void updatePetColorFunction(PetStore &psName)
{
	string listColor[5] = { "vang", "nau", "trang", "den", "xam" };
	string petUpdatedID;
	string newPetColor;
	cout << "Nhap vao thong tin cua pet can sua: ";
	cin >> petUpdatedID;
	Node* petUpdated = findPetByID(psName, petUpdatedID);

	while (petUpdated != NULL)
	{
		if (petUpdated->petData.petID == petUpdatedID)
		{
			do
			{
				cout << "Nhap mau moi cho pet: ";
				cin >> newPetColor;
				if (find(begin(listColor), end(listColor), newPetColor) == end(listColor))
				{
					cout << "Nhap mau thu cung khong hop le, vui long nhap lai!" << endl;
					cout << "5 mau sac hop le la vang, nau, trang, den, xam! " << endl;
				}
			} while (find(begin(listColor), end(listColor), newPetColor) == end(listColor));

			petUpdated->petData.petColor = newPetColor;
			cout << "Hoan thanh update mau pet!" << endl;
		}
		petUpdated = petUpdated->next;
	}
}

void printPetStoreFunction(PetStore &psName)
{
	if (psName.head == NULL)
	{
		cout << "Cua hang da het thu cung roi, vui long nhap them pet!" << endl;
	}
	else
	{
		Node* node = psName.head;
		while (node != NULL)
		{
			cout << "========================" << node->petData.petID << "=========================================" << endl;
			printPetData(node->petData);
			node = node->next;
		}
	}
}

void sellPetMenu(PetStore &psName, Node* petSoldData)
{
	int choice;
	do {
		cout << "Ban co dong y mua pet khong?" << endl;
		cout << "<1> Co			<2>Khong" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "Chuc mung " << petSoldData->petData.petName << " da ve nha moi!";
			delPetByID(psName, petSoldData->petData.petID);
			cout << endl;
		}
		else if (choice == 2)
		{
			cout << "Hen ban lan sau!" << endl;
		}
		else
		{
			cout << "Lua chon khong hop le, vui long chon lai!" << endl;
		}
	} while (choice != 2 && choice != 1);
}

void sellPetByIDFunction(PetStore &psName)
{
	string petIdFound;
	float totalBillOfPet = 0;
	cout << "Ma pet can tim: ";
	cin >> petIdFound;
	Node *petFound = findPetByID(psName, petIdFound);
	if (petFound == NULL)
	{
		cout << "Khong tim thay thong tin pet!";
	}
	else
	{
		printPetData(petFound->petData);
		cout << endl;
		cout << "Gia cua thu cung ban muon mua la: ";
		totalBillOfPet = 100 + (petFound->petData.petWeight * 2) - petFound->petData.petAge;
		cout << totalBillOfPet << " USD " << endl;
		sellPetMenu(psName, petFound);
	}

}

void menu()
{
	int choice;
	PetStore ps1;
	initPetStore(ps1);
	do {
		cout << "==================================MENU==================================" << endl;
		cout << "	<1> Khoi tao cua hang thu cung" << endl;
		cout << "	<2> Nhap thu cung va them thong tin vao cua hang" << endl;
		cout << "	<3> In ra danh sach thu cung vua nhap" << endl;
		cout << "	<4> Ban thu cung bang cach nhap ma" << endl;
		cout << "	<5> Them 1 thu cung vao 1 vi tri xac dinh trong danh sach" << endl;
		cout << "	<6> Cap nhat mau long cho thu cung voi ma so cho truoc" << endl;
		cout << "	<7> Xoa tat ca thu cung co trong luong lon hon nguong k" << endl;
		cout << "	<8> Exit" << endl;
		cout << "========================================================================" << endl;
		cout << "Your choice: ";
		cin >> choice;
		cout << "========================================================================" << endl;
		switch (choice) {
		case 1:
			system("cls");
			cout << "========================================================================" << endl;
			initPetStoreFunction(ps1);
			cout << endl;
			break;
		case 2:
			system("cls");
			cout << "========================================================================" << endl;
			addPetFunction(ps1);
			cout << endl;
			break;
		case 3:
			system("cls");
			cout << "========================================================================" << endl;
			printPetStoreFunction(ps1);
			cout << endl;
			break;
		case 4:
			system("cls");
			cout << "========================================================================" << endl;
			sellPetByIDFunction(ps1);
			cout << endl;
			break;
		case 5:
			system("cls");
			addPetAfterIdFunction(ps1);
			cout << endl;
			break;
		case 6:
			system("cls");
			cout << "========================================================================" << endl;
			updatePetColorFunction(ps1);
			cout << endl;
			break;
			system("cls");
		case 7:
			delPetByWeight(ps1);
			break;
		case 8:
			system("cls");
			cout << "End Program" << endl;
			exit(0);
			break;
		default:
			cout << "Not a valid choice" << endl;
		}
	} while (choice != 9);
}
