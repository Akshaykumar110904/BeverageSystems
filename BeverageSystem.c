#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct regis {
    int gn;
    char name[50];
    char ac[50];
    char phoneno[50];
    char sname[50];
    char pw[50];
} shop[200], rs;

struct brand {
    int bid;
    char bname[50];
    long mrp;
    int num;
} add[200], bl[200];

int main() {   
    struct brand b, r;
    FILE *fr, *fs, *fb, *fp;
    int ch, gz, i, j, k, m = 0, n, id[100], cs[100], c, d, x, y, z;
    double bil = 0;
    long mr[100], mp;
    char con, stat = 'n', cont = 'n', pd[50], sn[50], dt[20], fl[100], f[100];

    system("color F0");
    system("cls");
    printf("\t\t***======WELCOME TO BEVERAGES COOPERATION LIMITED======***");
    printf("\n========================================================================================================================");
    printf("\n\n\t\t Do you want to continue (y/n): ");
    scanf(" %c", &con);

    while (con == 'y' || con == 'Y') {
        printf("\n\tWhat do you want to do?");
        printf("\n\t1. Register your shop");
        printf("\n\t2. Add brand");
        printf("\n\t3. Display stock");
        printf("\n\t4. Do billing");
        printf("\n\t5. Refilling the stock");
        printf("\n\n\tPlease enter your choice:\t");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                system("cls");
                printf("Enter number of shops you want to register: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("\n\tEnter gazitte number:\t");
                    scanf("%d", &shop[i].gn);
                    printf("\nEnter the name of owner: ");
                    scanf(" %[^\n]s", shop[i].name);
                    printf("\nEnter your bank account: ");
                    scanf(" %[^\n]s", shop[i].ac);
                    printf("\nEnter your phone number: ");
                    scanf(" %[^\n]s", shop[i].phoneno);
                    printf("\nEnter the shop name: ");
                    scanf(" %[^\n]s", shop[i].sname);
                    printf("\nEnter your password: ");
                    scanf(" %[^\n]s", shop[i].pw);
                }
                fr = fopen("registration.dat", "ab");
                if (fr) {
                    fwrite(&shop, sizeof(struct regis), n, fr);
                    printf("\n**Registration of %d details completed successfully**", n);
                    fclose(fr);
                } else {
                    printf("\nError opening file for registration.");
                }
                break;

            case 2:
                system("cls");
                fs = fopen("stock.dat", "rb");
                if (fs) {
                    fseek(fs, 0, SEEK_END);
                    m = ftell(fs) / sizeof(struct brand);
                    rewind(fs);
                    fread(&add, sizeof(struct brand), m, fs);
                    printf("\n\tThe Available Stock is:");
                    printf("\nID\tBRAND NAME\t\tMRP\t\tCASES");
                    printf("\n=========================================================================================================================");
                    for (i = 0; i < m; i++) {
                        printf("\n%d\t%s\t\t%ld\t\t%d", add[i].bid, add[i].bname, add[i].mrp, add[i].num);
                    }
                    fclose(fs);
                }
                
                printf("\nEnter no of brands you want to enter: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    add[i].bid = m + (i + 1);
                    printf("\nEnter %d brand name:\t", i + 1);
                    scanf(" %[^\n]s", add[i].bname);
                    printf("\nEnter %d brand price per case:\t", i + 1);
                    scanf("%ld", &add[i].mrp);
                    printf("\nEnter %d brand number of cases:\t", i + 1);
                    scanf("%d", &add[i].num);
                }
                fs = fopen("stock.dat", "ab");
                if (fs) {
                    fwrite(&add, sizeof(struct brand), n, fs);
                    printf("\n===Adding of New Brands Completed Successfully===");
                    fclose(fs);
                } else {
                    printf("\nError opening file for adding brands.");
                }
                break;

            case 3: 
                system("cls");
                fs = fopen("stock.dat", "rb");
                if (fs) {
                    fseek(fs, 0, SEEK_END);
                    n = ftell(fs) / sizeof(struct brand);
                    rewind(fs);
                    fread(&add, sizeof(struct brand), n, fs);
                    printf("\n\tThe Available Stock is:");
                    printf("\nID\tBRAND NAME\t\tMRP\t\tCASES");
                    printf("\n=========================================================================================================================");
                    for (i = 0; i < n; i++) {
                        printf("\n%d\t\t%s\t\t%ld\t\t%d", add[i].bid, add[i].bname, add[i].mrp, add[i].num);    
                    }
                    fclose(fs);
                } else {
                    printf("\nError opening file for displaying stock.");
                }
                break;

            case 4:
                system("cls");
                printf("enter today's date: ");
                scanf(" %[^\n]s", dt);
                printf("enter gazitte number: ");
                scanf("%d", &gz);
                printf("enter shop name: ");
                scanf(" %[^\n]s", sn);
                
                printf("enter password: ");
                scanf(" %[^\n]s", pd);
                fr = fopen("registration.dat", "rb");
                
                if(fr) {
                    fseek(fr, 0, SEEK_END);
                    m = ftell(fr) / sizeof(struct regis);
                    rewind(fr);
                    fread(&shop, sizeof(struct regis), m, fr);
                    fclose(fr);
                } else {
                    printf("\nError opening registration file.");
                    break;
                }
                
                int authenticated = 0;
                for(i = 0; i < m; i++) {
                    if((gz == shop[i].gn) && (strcmp(shop[i].pw, pd) == 0)) {
                        authenticated = 1;
                        printf("\nWelcome to billing");
                        
                        fs = fopen("stock.dat", "rb");
                        if(fs) {
                            fseek(fs, 0, SEEK_END);
                            n = ftell(fs) / sizeof(struct brand);
                            rewind(fs);
                            fread(&add, sizeof(struct brand), n, fs);
                            printf("\n\tThe Available Stock is:");
                            printf("\nID\tBRAND NAME\t\tMRP\t\tCASES");
                            
                            printf("\n======================================================================================================================");
                            
                            for(j = 0; j < n; j++) {
                                printf("\n%d\t\t%s\t\t%ld\t\t%d", add[j].bid, add[j].bname, add[j].mrp, add[j].num);
                            }
                            fclose(fs);
                        }
                        
                        printf("\nenter number of brands you want to order: ");
                        scanf("%d", &k);
                        fs = fopen("stock.dat", "rb+");
                        
                        for(j = 0; j < k; j++) {
                            printf("\nenter brand id: ");
                            scanf("%d", &d);
                            
                            stat = 'n';
                            rewind(fs);
                            while((fread(&r, sizeof(struct brand), 1, fs)) == 1) {
                                if(d == r.bid) {
                                    stat = 'f';
                                    break;
                                }
                            }
                            
                            if(stat == 'f') {
                                printf("enter number of cases: ");
                                scanf("%d", &c);
                                x = y = c;
                                id[j] = d;
                                b.bid = r.bid;
                                strcpy(b.bname, r.bname);
                                b.mrp = r.mrp;
                                
                                if(r.num >= x) {
                                    cs[j] = y;
                                    b.num = (r.num - x);
                                    mr[j] = cs[j] * b.mrp;
                                } else {
                                    cs[j] = r.num;
                                    b.num = 0;
                                    mr[j] = cs[j] * b.mrp;
                                    printf("Only %d cases available, adjusted quantity.\n", r.num);
                                }
                                
                                fseek(fs, -sizeof(struct brand), 1);
                                fwrite(&b, sizeof(struct brand), 1, fs);
                            }
                        }
                        fclose(fs);
                        fs = fopen("stock.dat", "rb");
                        for(j = 0; j < k; j++) {
                            rewind(fs);
                            while((fread(&r, sizeof(struct brand), 1, fs)) == 1) {
                                if(id[j] == r.bid) {
                                    cont = 'y';
                                    break;
                                }
                            }
                            
                            if(cont == 'y') {
                                bl[j].bid = (j + 1);
                                strcpy(bl[j].bname, r.bname);
                                bl[j].mrp = mr[j];
                                bl[j].num = cs[j];
                            }
                        }
                        fclose(fs);
                        strcpy(fl, sn);
                        strcat(fl, dt);
                        strcat(fl, ".txt");
                        fb = fopen(fl, "w");
                        if(fb) {
                            fprintf(fb, "shop name:\t%s\t\tgazitte number:\t%d\t\tdate=%s\n", sn, gz, dt);
                            fprintf(fb, "Owner name:\t%s\t\tPhone number:\t%s\n", shop[i].name, shop[i].phoneno);
                            fprintf(fb, "\nSL.NO\tBRAND NAME\t\tAMOUNT\t\tCASES\n");
                            fprintf(fb, "============================================\n");
                            
                            bil = 0;
                            for(j = 0; j < k; j++) {
                                bil += bl[j].mrp;
                                fprintf(fb, "%d\t%s\t\t%ld\t\t%d\n", bl[j].bid, bl[j].bname, bl[j].mrp, bl[j].num);
                            }
                            
                            fprintf(fb, "\nTOTAL BILL=%.2f", bil);
                            fclose(fb);
                            printf("\nBill generated successfully! File: %s", fl);
                            printf("\nTotal Bill: %.2f", bil);
                        }
                        break;
                    }
                }
                
                if(!authenticated) {
                    printf("\nAuthentication failed! Invalid gazette number or password.");
                }
                break;
                
            case 5:
                system("cls");
                fs = fopen("stock.dat", "rb");
                if(fs) {
                    fseek(fs, 0, SEEK_END);
                    n = ftell(fs) / sizeof(struct brand);
                    rewind(fs);
                    fread(&add, sizeof(struct brand), n, fs);
                    printf("\n\t\tThe Available Stock is:");
                    printf("\n\t\tID\tBRAND NAME\t\tMRP\t\tCASES");
                    printf("\n\t\t===============================================");
                    for(i = 0; i < n; i++) {
                        printf("\n\t\t%d\t%s\t\t%ld\t\t%d", add[i].bid, add[i].bname, add[i].mrp, add[i].num);
                    }
                    fclose(fs);
                    
                    printf("\n\t\tenter number of brands you want to refill: ");
                    scanf("%d", &m);
                    fs = fopen("stock.dat", "rb+");
                    for(i = 0; i < m; i++) {
                        printf("\n\t\tenter brand id: ");
                        scanf("%d", &d);
                        
                        stat = 'n';
                        rewind(fs);
                        while((fread(&r, sizeof(struct brand), 1, fs)) == 1) {
                            if(d == r.bid) {
                                stat = 'f';
                                break;
                            }
                        }
                        
                        if(stat == 'f') {
                            printf("\n\t\tenter number of cases: ");
                            scanf("%d", &c);
                            b.bid = r.bid;
                            strcpy(b.bname, r.bname);
                            b.mrp = r.mrp;
                            b.num = (r.num + c);
                            fseek(fs, -sizeof(struct brand), 1);
                            fwrite(&b, sizeof(struct brand), 1, fs);
                            printf("\n\t\tStock refilled successfully!");
                        } else {
                            printf("\n\t\tBrand ID not found!");
                        }
                    }
                    fclose(fs);
                } else {
                    printf("\nError opening stock file.");
                }
                break;
                
            default:
                printf("\nInvalid choice");
        }
        
        printf("\n\nDo you want to continue (y/n): ");
        scanf(" %c", &con);
        system("cls");
    }
    
    printf("\n\n\t\t***THANK YOU FOR USING BEVERAGES MANAGEMENT SYSTEM***");
    return 0;
}
