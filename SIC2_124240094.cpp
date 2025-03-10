#include <iostream>
using namespace std;

int total = 0;
struct Mahasiswa
{
    string nama;
    int nim;
    char kelas;
    float ipk;
};

void tampilmenu(int &menu)
{
    cout << "+------------------+" << endl;
    cout << "|   Menu Pilihan   |" << endl;
    cout << "+------------------+" << endl;
    cout << "| 1. Input Data    |" << endl;
    cout << "| 2. Tampil Data   |" << endl;
    cout << "| 3. Searching     |" << endl;
    cout << "| 4. Sorting       |" << endl;
    cout << "| 5. Exit          |" << endl;
    cout << "+------------------+" << endl;
    cout << "Pilih Menu[1-5]: ";
    cin >> menu;
}
void inputdata(Mahasiswa mahasiswa[])
{
    int banyak;
    cout << "Banyak Data Mahasiswa: ";
    cin >> banyak;
    cout << endl
         << endl;
    for (int i = 0; i < banyak; i++)
    {
        cout << "Data Mahasiswa Ke-" << total + 1 << ":" << endl;
        cout << "Masukan NIM            : ";
        cin >> mahasiswa[total].nim;
        cout << "Masukan Nama           : ";
        cin.ignore();
        getline(cin, mahasiswa[total].nama);
        cout << "Masukan Kelas          : ";
        cin >> mahasiswa[total].kelas;
        cout << "Maasukan IPK           : ";
        cin >> mahasiswa[total].ipk;
        cout << endl;

        total++; // Menambah jumlah total barang setelah input
    }
}
void tampilData(Mahasiswa mahasiswa[], int total)
{
    cout << "=============== Data Mahasiswa ================\n";
    cout << "Data Mahasiswa saat Ini : " << total << endl
         << endl;
    cout << "===============================================\n";
    cout << "No\tNama\t\tNIM\tKelas\tIPK\n";
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < total; i++)
    {
        cout << i + 1 << "\t" << mahasiswa[i].nama << "\t\t" << mahasiswa[i].nim << "\t" << mahasiswa[i].kelas << "\t" << mahasiswa[i].ipk << endl;
    }
    cout << "===============================================\n";
}
void tampilmenusearch(int &menusearch)
{
    cout << "==========================================" << endl;
    cout << "|               Menu Search              |" << endl;
    cout << ".........................................." << endl;
    cout << "|1. Berdasarkan Nama (sequential Search) |" << endl;
    cout << "|2. Berdasarkan NIM (Binary Search)      |" << endl;
    cout << "|3. Kembali                              |" << endl;
    cout << "==========================================" << endl;
    cout << "Pilih Menu[1-3]: ";
    cin >> menusearch;
}
// sequential search
void carinamamhs(Mahasiswa mahasiswa[], int total)
{
    string nilaicari;
    bool found = false;

    cout << "=============================================\n";
    cout << "         PENCARIAN BERDASARKAN NAMA        \n";
    cout << "=============================================\n";
    cout << "Masukkan Nama Mahasiswa yang akan dicari: ";
    cin.ignore();
    getline(cin, nilaicari);
    cout << endl
         << endl;
    for (int i = 0; i < total; i++)
    {
        if (mahasiswa[i].nama == nilaicari)
        {
            if (!found)
            {
                cout << "===============================================\n";
                cout << "No\tNama\t\tNIM\tKelas\tIPK\n";
                cout << "-----------------------------------------------\n";
                found = true;
            }
            cout << i + 1 << "\t" << mahasiswa[i].nama << "\t\t" << mahasiswa[i].nim << "\t" << mahasiswa[i].kelas << "\t" << mahasiswa[i].ipk << " \n";
        }
    }
    if (found)
    {
        cout << "===============================================\n";
    }
    else
    {
        cout << "=============================================\n";
        cout << " Mahasiswa dengan nama \"" << nilaicari << "\" tidak ditemukan.   \n";
        cout << "=============================================\n";
    }
}
// binary search
void carinimmhs(Mahasiswa mahasiswa[], int total)
{
    int nilaicari;
    bool found = false;
    int awal = 0, akhir = total - 1, tengah;
    for (int i = 0; i < total - 1; i++)
    {
        for (int j = 0; j < total - 1 - i; j++)
        {
            if (mahasiswa[j].nim > mahasiswa[j + 1].nim)
            {
                swap(mahasiswa[j], mahasiswa[j + 1]);
            }
        }
    }
    cout << "=============================================\n";
    cout << "           PENCARIAN BERDASARKAN NIM         \n";
    cout << "=============================================\n";
    cout << "Masukkan NIM Mahasiswa yang akan dicari: ";
    cin >> nilaicari;
    cout << endl
         << endl;
    while (awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (mahasiswa[tengah].nim == nilaicari)
        {
            found = true;
            cout << "===============================================\n";
            cout << "No\tNama\t\tNIM\tKelas\tIPK\n";
            cout << "-----------------------------------------------\n";
            cout << tengah + 1 << "\t" << mahasiswa[tengah].nama << "\t\t" << mahasiswa[tengah].nim << "\t" << mahasiswa[tengah].kelas << "\t" << mahasiswa[tengah].ipk << "\n";
            cout << "---------------------------------------------\n";
            break;
        }
        if (mahasiswa[tengah].nim > nilaicari)
        {
            akhir = tengah - 1;
        }
        else
        {
            awal = tengah + 1;
        }
    }
    if (!found)
    {
        cout << "=============================================\n";
        cout << "   Mahasiswa dengan NIM " << nilaicari << " tidak ditemukan.   \n";
        cout << "=============================================\n";
    }
}
void tampilmenusorting(int &menusorting)
{
    cout << "+--------------------------------------+" << endl;
    cout << "|             MENU SORTING             |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "| 1. Berdasarkan NIM (Bubble Sort)     |" << endl;
    cout << "| 2. Berdasarkan Nama (Selection Sort) |" << endl;
    cout << "| 3. Berdasarkan Kelas (Insertion Sort)|" << endl;
    cout << "| 4. Berdasarkan IPK (Shell Sort)      |" << endl;
    cout << "| 5. Keluar                            |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "Pilih Menu[1-5]: ";
    cin >> menusorting;
}
void tampilsorting(Mahasiswa mahasiswa[], int total)
{
    cout << endl
         << endl;
    cout << "======= Data Mahasiswa Setelah Sorting ========" << endl;
    cout << "Data Mahasiswa saat Ini : " << total << endl
         << endl;
    cout << "===============================================" << endl;
    cout << "No\tNama\t\tNIM\tKelas\tIPK\n";
    cout << "..............................................." << endl;
    for (int i = 0; i < total; i++)
    {
        cout << i + 1 << "\t" << mahasiswa[i].nama << "\t\t" << mahasiswa[i].nim << "\t" << mahasiswa[i].kelas << "\t" << mahasiswa[i].ipk << endl;
    }
    cout << "===============================================" << endl;
}
void bubblesort(Mahasiswa mahasiswa[], int total)
{
    for (int i = 0; i < total - 1; i++)
    {
        cout << "Iterasi ke-" << i + 1 << ": ";
        for (int x = 0; x < total; x++)
        {
            cout << mahasiswa[x].nim << " ";
        }
        cout << endl;

        for (int j = 0; j < total - 1 - i; j++)
        {
            if (mahasiswa[j].nim > mahasiswa[j + 1].nim)
            {
                swap(mahasiswa[j], mahasiswa[j + 1]);
            }
        }
    }
}
void Selectionsort(Mahasiswa mahasiswa[], int total)
{
    int i = 0, j, k;
    for (i = 0; i < total - 1; i++)
    {
        k = i;                          // anggep elemen pertama sebagai elemen terkecil
        for (j = i + 1; j < total; j++) // cari elemen terkecil di sisa array
        {
            if (mahasiswa[j].nama < mahasiswa[k].nama) // bandingkan berdasarkan nama
            {
                k = j; // simpa indeks elemen terkecil
            }
        }
        swap(mahasiswa[i], mahasiswa[k]); // Tukar Posisi
        // menampilkan hasil iterasi sorting
        cout << "Iterasi ke-" << i + 1 << ":\n";
        for (int x = 0; x < total; x++)
        {
            cout << x + 1 << ". " << mahasiswa[x].nama << " - " << mahasiswa[x].nim << " - " << mahasiswa[x].kelas << " - " << mahasiswa[x].ipk << endl;
        }
        cout << endl;
    }
}
void insertionsort(Mahasiswa mahasiswa[], int total)
{
    int i, j;
    Mahasiswa temp;
    for (i = 1; i < total; i++)
    {
        temp = mahasiswa[i]; // Simpan data sementara
        j = i - 1;
        // Mengurutkan berdasarkan kelas secara alfabetis (A-Z)
        while (j >= 0 && mahasiswa[j].kelas > temp.kelas)
        {
            mahasiswa[j + 1] = mahasiswa[j]; // Geser elemen ke kanan
            j = j - 1;
        }
        mahasiswa[j + 1] = temp; // Tempatkan elemen di posisi yang benar
    }
}
void shellsort(Mahasiswa mahasiswa[], int total)
{
    int i, j, k;
    for (i = total / 2; i > 0; i /= 2)
    {
        for (j = i; j < total; j++)
        {
            for (k = j - i; k >= 0; k -= i)
            {
                if (mahasiswa[k + i].ipk < mahasiswa[k].ipk)
                    swap(mahasiswa[k], mahasiswa[k + i]);
            }
        }
    }
}
void opsilain()
{
    cout << "========================================  " << endl;
    cout << "  Pilihan tidak Valid, silakan coba lagi  " << endl;
    cout << "========================================  " << endl;
}
void berhenti()
{
    char pilihan;
    cout << "Apakah Anda Ingin Kembali ke Menu Awal? (y/n): ";
    cin >> pilihan;

    if (pilihan == 'y' || pilihan == 'Y')
    {
        system("cls");
    }
    else if (pilihan == 'n' || pilihan == 'N')
    {
        cout << "Program selesai.\n";
        exit(0);
    }
    else
    {
        opsilain();
        berhenti();
    }
}
int main()
{
    int menu, cari, menusearch, menusorting;
    Mahasiswa mahasiswa[10000];
    do
    {
        tampilmenu(menu);
        system("cls");

        switch (menu)
        {
        case 1:
            inputdata(mahasiswa);
            berhenti();
            break;
        case 2:
            tampilData(mahasiswa, total);
            berhenti();
            break;
        case 3:
            do
            {
                tampilmenusearch(menusearch);
                system("cls");
                switch (menusearch)
                {
                case 1:
                    carinamamhs(mahasiswa, total);
                    berhenti();
                    break;
                case 2:
                    carinimmhs(mahasiswa, total);
                    berhenti();
                    break;
                case 3:
                    break;
                default:
                    opsilain();
                    berhenti();
                    break;
                }
            } while (menusearch != 3);
            break;
        case 4:
            do
            {
                tampilmenusorting(menusorting);
                system("cls");
                switch (menusorting)
                {
                case 1:
                    bubblesort(mahasiswa, total);
                    tampilsorting(mahasiswa, total);
                    berhenti();
                    break;
                case 2:
                    Selectionsort(mahasiswa, total);
                    tampilsorting(mahasiswa, total);
                    berhenti();
                    break;
                case 3:
                    insertionsort(mahasiswa, total);
                    tampilsorting(mahasiswa, total);
                    berhenti();
                    break;
                case 4:
                    shellsort(mahasiswa, total);
                    tampilsorting(mahasiswa, total);
                    berhenti();
                    break;
                case 5:
                    break;
                default:
                    opsilain();
                    berhenti();
                    break;
                }
            } while (menusorting != 5);
            berhenti();
            break;
        case 5:
            exit(0);
            break;
        default:
            opsilain();
            berhenti();
            break;
        }
    } while (menu != 5);
    return 0;
}