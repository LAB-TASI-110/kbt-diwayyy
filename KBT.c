#include <stdio.h>   
#include <stdlib.h> 
#include <string.h>  
#include <time.h>   
typedef struct {
    char departure_location[50]; 
    char destination[50];
    int price; 
    char departure_time[20];
    char vehicle_plate[10];
    int quantity;
    char payment_method[20];
    long transaction_id;
} Ticket;


long generateTransactionId() {
    return (long)rand() * 1000 + (rand() % 1000);
}

int main() {
   
    srand(time(NULL));

    char locations[][50] = {"Medan", "Pematangsiantar", "Doloksanggul", "Parapat", "Balige", "Tarutung"};
    int num_locations = sizeof(locations) / sizeof(locations[0]);

  
    int prices_per_destination[] = {150000, 100000, 120000, 75000, 50000, 90000}; 
    
   
    char departure_times[][20] = {"08:00 AM", "10:00 AM", "02:00 PM", "04:00 PM", "06:00 PM"};
    char vehicle_plates[][10] = {"BK1234AB", "BK5678CD", "BK9012EF", "BK3456GH", "BK7890IJ"}; 
    char payment_methods[][20] = {"Tunai", "Transfer Bank", "E-Wallet"};


    printf("===========================================\n");
    printf("     Selamat Datang di Sistem Ticketing    \n");
    printf("         Koperasi Bintang Tapanuli         \n");
    printf("===========================================\n");
    printf("Kami melayani berbagai rute antar kota di wilayah Tapanuli dan sekitarnya.\n");
    printf("\n");

    char choice_continue; 
    do {
        Ticket current_ticket;
        int departure_choice, dest_choice, time_choice, payment_choice;
        int num_tickets;
        int valid_input; 

        printf("-------------------------------------------\n");
        printf("          Pemesanan Tiket Baru             \n");
        printf("-------------------------------------------\n");

      
        printf("Daftar Lokasi Tersedia:\n");
        for (int i = 0; i < num_locations; i++) {
            printf("%d. %s\n", i + 1, locations[i]);
        }
        do {
            printf("Masukkan pilihan lokasi keberangkatan (1-%d): ", num_locations);
            valid_input = scanf("%d", &departure_choice);
            while (getchar() != '\n'); 
            if (!valid_input || departure_choice < 1 || departure_choice > num_locations) {
                printf("Pilihan tidak valid. Silakan masukkan angka sesuai daftar.\n");
            }
        } while (!valid_input || departure_choice < 1 || departure_choice > num_locations);
        strcpy(current_ticket.departure_location, locations[departure_choice - 1]);

 
        printf("\nPilih Tujuan Perjalanan:\n");
        for (int i = 0; i < num_locations; i++) {
            printf("%d. %s\n", i + 1, locations[i]);
        }
        do {
            printf("Masukkan pilihan tujuan (1-%d): ", num_locations);
            valid_input = scanf("%d", &dest_choice);
            while (getchar() != '\n'); 
            if (!valid_input || dest_choice < 1 || dest_choice > num_locations) {
                printf("Pilihan tidak valid. Silakan masukkan angka sesuai daftar.\n");
            } else if (dest_choice == departure_choice) {
                printf("Maaf, Koperasi Bintang Tapanuli tidak melayani perjalanan dari dan ke daerah yang sama.\n");
                printf("Silakan pilih tujuan yang berbeda dari lokasi keberangkatan.\n");
                valid_input = 0;
            }
        } while (!valid_input || dest_choice < 1 || dest_choice > num_locations || dest_choice == departure_choice);
        
        strcpy(current_ticket.destination, locations[dest_choice - 1]);
        current_ticket.price = prices_per_destination[dest_choice - 1]; 
       
        printf("\n===========================================\n");
        printf("   Selamat Datang di Pemesanan Tiket       \n");
        printf("       Rute: %s -> %s\n", current_ticket.departure_location, current_ticket.destination);
        printf("===========================================\n");
        printf("Harga per tiket untuk rute ini: Rp %d\n", current_ticket.price);
        printf("\n");

        
        do {
            printf("Berapa jumlah tiket yang ingin dibeli? (minimal 1): ");
            valid_input = scanf("%d", &num_tickets);
            while (getchar() != '\n');
            if (!valid_input || num_tickets < 1) {
                printf("Jumlah tiket tidak valid. Silakan masukkan angka positif.\n");
            }
        } while (!valid_input || num_tickets < 1);
        current_ticket.quantity = num_tickets;

        long total_price = (long)current_ticket.price * current_ticket.quantity;
        printf("Total harga untuk %d tiket: Rp %ld\n\n", num_tickets, total_price);


        printf("Pilih Metode Pembayaran:\n");
        for (int i = 0; i < sizeof(payment_methods) / sizeof(payment_methods[0]); i++) {
            printf("%d. %s\n", i + 1, payment_methods[i]);
        }
        do {
            printf("Masukkan pilihan pembayaran (1-%d): ", (int)(sizeof(payment_methods) / sizeof(payment_methods[0])));
            valid_input = scanf("%d", &payment_choice);
            while (getchar() != '\n'); 
            if (!valid_input || payment_choice < 1 || payment_choice > (int)(sizeof(payment_methods) / sizeof(payment_methods[0]))) {
                printf("Pilihan tidak valid. Silakan masukkan angka sesuai daftar.\n");
            }
        } while (!valid_input || payment_choice < 1 || payment_choice > (int)(sizeof(payment_methods) / sizeof(payment_methods[0])));
        
        strcpy(current_ticket.payment_method, payment_methods[payment_choice - 1]);

  
        printf("Pilih Jam Keberangkatan:\n");
        for (int i = 0; i < sizeof(departure_times) / sizeof(departure_times[0]); i++) {
            printf("%d. %s\n", i + 1, departure_times[i]);
        }
        do {
            printf("Masukkan pilihan jam keberangkatan (1-%d): ", (int)(sizeof(departure_times) / sizeof(departure_times[0])));
            valid_input = scanf("%d", &time_choice);
            while (getchar() != '\n'); 
            if (!valid_input || time_choice < 1 || time_choice > (int)(sizeof(departure_times) / sizeof(departure_times[0]))) {
                printf("Pilihan tidak valid. Silakan masukkan angka sesuai daftar.\n");
            }
        } while (!valid_input || time_choice < 1 || time_choice > (int)(sizeof(departure_times) / sizeof(departure_times[0])));
        
        strcpy(current_ticket.departure_time, departure_times[time_choice - 1]);

 
        strcpy(current_ticket.vehicle_plate, vehicle_plates[rand() % (sizeof(vehicle_plates) / sizeof(vehicle_plates[0]))]);


        current_ticket.transaction_id = generateTransactionId();


        printf("\n===========================================\n");
        printf("           INVOICE PEMESANAN TIKET         \n");
        printf("           KOPERASI BINTANG TAPANULI       \n");
        printf("===========================================\n");
        printf("ID Transaksi        : %ld\n", current_ticket.transaction_id);
        printf("Lokasi Keberangkatan: %s\n", current_ticket.departure_location); 
        printf("Tujuan Perjalanan   : %s\n", current_ticket.destination);
        printf("Harga per Tiket     : Rp %d\n", current_ticket.price);
        printf("Jumlah Tiket        : %d\n", current_ticket.quantity);
        printf("Total Pembayaran    : Rp %ld\n", total_price);
        printf("Metode Pembayaran   : %s\n", current_ticket.payment_method);
        printf("Jam Keberangkatan   : %s\n", current_ticket.departure_time);
        printf("Nomor Kendaraan     : %s\n", current_ticket.vehicle_plate);
        printf("===========================================\n\n");

        printf("Apakah Anda ingin memesan tiket lagi? (y/n): ");
        scanf(" %c", &choice_continue); 
        while (getchar() != '\n');
        printf("\n");

    } while (choice_continue == 'y' || choice_continue == 'Y');

    printf("Terima kasih telah menggunakan sistem ticketing Koperasi Bintang Tapanuli.\n");
    printf("===========================================\n");

    return 0;
}
