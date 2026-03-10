# 🏥 Hospital Management System (HMS)

A lightweight and efficient **Hospital Management System** implemented in C. This project demonstrates the power of structured data and binary file handling to manage patient records with persistence.

---

## 🚀 Features

* **➕ Add Patient**: Register new patients with a unique ID and medical history.
* **📋 View All Patients**: Display a formatted list of all records stored in the system.
* **🔍 Search Patient**: Quickly find specific patient details using their unique ID.
* **🗑️ Delete Patient**: Remove records from the system permanently.
* **💾 Persistent Storage**: Data is saved in a binary file (`patients.dat`), so your information isn't lost when you close the program.

---

## 🛠️ Data Structure

The system uses a custom `struct` to ensure data integrity for every entry:

| Field | Type | Description |
| :--- | :--- | :--- |
| `id` | `int` | Unique Patient ID |
| `name` | `string` | Full name of the patient |
| `age` | `int` | Age of the patient |
| `gender` | `string` | Patient's gender |
| `disease`| `string` | Diagnosed condition |

---

## 💻 Getting Started

### Prerequisites

* A C compiler (e.g., **GCC**, **Clang**, or **MinGW**)
* Basic knowledge of the command line

### Compilation and Execution

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/your-username/hospital-management-system.git](https://github.com/your-username/hospital-management-system.git)
    cd hospital-management-system
    ```

2.  **Compile the source code:**
    ```bash
    gcc HSY.c -o HospitalManagementSystem
    ```

3.  **Run the application:**
    ```bash
    ./HospitalManagementSystem
    ```

---

## 📂 Project Structure

* `HSY.c`: The core source code containing the logic and file operations.
* `patients.dat`: The binary database file (automatically generated).
* `README.md`: Documentation for the project.

---

## 🤝 Contributing

Contributions make the open-source community an amazing place! If you have suggestions for improvements (like adding an **Update** or **Sort** feature), feel free to:

1.  **Fork** the project.
2.  Create your **Feature Branch** (`git checkout -b feature/NewFeature`).
3.  **Commit** your changes (`git commit -m 'Add some NewFeature'`).
4.  **Push** to the branch (`git push origin feature/NewFeature`).
5.  Open a **Pull Request**.

---
