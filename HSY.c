#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
};

FILE *fp;

void addPatient() {
    struct Patient p;
    fp = fopen("patients.dat", "ab");

    printf("Enter Patient ID: ");
    scanf("%d", &p.id);
    getchar(); // clear newline
    printf("Enter Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;
    printf("Enter Age: ");
    scanf("%d", &p.age);
    getchar();
    printf("Enter Gender: ");
    fgets(p.gender, sizeof(p.gender), stdin);
    p.gender[strcspn(p.gender, "\n")] = 0;
    printf("Enter Disease: ");
    fgets(p.disease, sizeof(p.disease), stdin);
    p.disease[strcspn(p.disease, "\n")] = 0;

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
    printf("✅ Patient record added.\n");
}

void viewPatients() {
    struct Patient p;
    fp = fopen("patients.dat", "rb");

    printf("\n--- All Patient Records ---\n");

    while (fread(&p, sizeof(p), 1, fp)) {
        printf("\nID: %d\nName: %s\nAge: %d\nGender: %s\nDisease: %s\n",
               p.id, p.name, p.age, p.gender, p.disease);
    }

    fclose(fp);
}

void searchPatient() {
    int id, found = 0;
    struct Patient p;
    fp = fopen("patients.dat", "rb");

    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            printf("\nPatient Found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nGender: %s\nDisease: %s\n",
                   p.id, p.name, p.age, p.gender, p.disease);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("❌ Patient not found.\n");

    fclose(fp);
}

void deletePatient() {
    int id, found = 0;
    struct Patient p;
    FILE *temp;

    fp = fopen("patients.dat", "rb");
    temp = fopen("temp.dat", "wb");

    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id != id) {
            fwrite(&p, sizeof(p), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("patients.dat");
    rename("temp.dat", "patients.dat");

    if (found)
        printf("🗑️ Patient record deleted.\n");
    else
        printf("❌ Patient not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n🏥 Hospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. View All Patients\n");
        printf("3. Search Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                deletePatient();
                break;
            case 5:
                printf("👋 Exiting system. Stay healthy!\n");
                break;
            default:
                printf("⚠️ Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
