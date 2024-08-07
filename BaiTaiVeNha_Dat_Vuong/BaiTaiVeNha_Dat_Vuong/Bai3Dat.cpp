#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 5
#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 15

typedef struct {
    char subjectCode[MAX_ID_LENGTH];
    char subjectName[MAX_NAME_LENGTH];
    int credit;
    float score;
} Subject;

typedef struct {
    char studentID[MAX_ID_LENGTH];
    char studentName[MAX_NAME_LENGTH];
    Subject subjects[MAX_SUBJECTS];
    float averageScore;
} Student;

void inputStudentList(Student* students, int n);
void outputStudentList(Student* students, int n);
int findStudentByID(Student* students, int n, char* studentID);
int findStudentWithHighestAverageScore(Student* students, int n);
void addStudent(Student* students, int* n, Student newStudent);
void deleteStudent(Student* students, int* n, char* studentID);
void sortStudentsByAverageScore(Student* students, int n, int ascending);
void classifyStudent(Student* student);
void countPassedFailedSubjects(Student* student);

int main() {
    int n = 3;
    Student students[100] = {
        {
            "SV001", "Nguyen Van A",
            {
                {"MH001", "Nhap mon lap trinh", 3, 7.5},
                {"MH002", "Toan A1", 3, 8.0},
                {"MH003", "Toan A2", 3, 6.0},
                {"MH004", "Vat ly ky thuat", 3, 5.5},
                {"MH005", "Anh van", 3, 7.0}
            },
            6.8
        },
        {
            "SV002", "Le Thi B",
            {
                {"MH001", "Nhap mon lap trinh", 3, 9.0},
                {"MH002", "Toan A1", 3, 8.5},
                {"MH003", "Toan A2", 3, 7.0},
                {"MH004", "Vat ly ky thuat", 3, 6.5},
                {"MH005", "Anh van", 3, 8.0}
            },
            7.8
        },
        {
            "SV003", "Tran Van C",
            {
                {"MH001", "Nhap mon lap trinh", 3, 4.0},
                {"MH002", "Toan A1", 3, 5.0},
                {"MH003", "Toan A2", 3, 6.0},
                {"MH004", "Vat ly ky thuat", 3, 5.0},
                {"MH005", "Anh van", 3, 4.5}
            },
            4.9
        }
    };

    // Output students
    printf("\nStudent List:\n");
    outputStudentList(students, n);

    // Find a student by ID
    char searchID[MAX_ID_LENGTH];
    printf("\nEnter student ID to search: ");
    scanf("%s", searchID);
    int index = findStudentByID(students, n, searchID);
    if (index != -1) {
        printf("Student found:\n");
        outputStudentList(&students[index], 1);
    }
    else {
        printf("Student not found.\n");
    }

    // Find student with highest average score
    int highestIndex = findStudentWithHighestAverageScore(students, n);
    printf("\nStudent with highest average score:\n");
    outputStudentList(&students[highestIndex], 1);

    // Sort students by average score
    sortStudentsByAverageScore(students, n, 1);
    printf("\nStudents sorted by average score (ascending):\n");
    outputStudentList(students, n);

    // Add a new student
    Student newStudent = {
        "SV004", "Pham Thi D",
        {
            {"MH001", "Nhap mon lap trinh", 3, 7.0},
            {"MH002", "Toan A1", 3, 8.0},
            {"MH003", "Toan A2", 3, 7.5},
            {"MH004", "Vat ly ky thuat", 3, 6.0},
            {"MH005", "Anh van", 3, 7.5}
        },
        7.2
    };
    addStudent(students, &n, newStudent);
    printf("\nUpdated Student List:\n");
    outputStudentList(students, n);

    // Delete a student
    printf("\nEnter student ID to delete: ");
    scanf("%s", searchID);
    deleteStudent(students, &n, searchID);
    printf("\nUpdated Student List:\n");
    outputStudentList(students, n);

    // Classify and count subjects for each student
    for (int i = 0; i < n; i++) {
        classifyStudent(&students[i]);
        countPassedFailedSubjects(&students[i]);
    }

    return 0;
}



void inputStudentList(Student* students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter student ID: ");
        scanf("%s", students[i].studentID);
        printf("Enter student name: ");
        scanf(" %[^\n]", students[i].studentName);
        float totalScore = 0;
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("Enter subject code: ");
            scanf("%s", students[i].subjects[j].subjectCode);
            printf("Enter subject name: ");
            scanf(" %[^\n]", students[i].subjects[j].subjectName);
            printf("Enter subject credit: ");
            scanf("%d", &students[i].subjects[j].credit);
            printf("Enter subject score: ");
            scanf("%f", &students[i].subjects[j].score);
            totalScore += students[i].subjects[j].score;
        }
        students[i].averageScore = totalScore / MAX_SUBJECTS;
    }
}

void outputStudentList(Student* students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Student ID: %s\n", students[i].studentID);
        printf("Student Name: %s\n", students[i].studentName);
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("Subject Code: %s, Subject Name: %s, Credit: %d, Score: %.2f\n",
                students[i].subjects[j].subjectCode,
                students[i].subjects[j].subjectName,
                students[i].subjects[j].credit,
                students[i].subjects[j].score);
        }
        printf("Average Score: %.2f\n", students[i].averageScore);
    }
}

int findStudentByID(Student* students, int n, char* studentID) {
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].studentID, studentID) == 0) {
            return i;
        }
    }
    return -1;
}

int findStudentWithHighestAverageScore(Student* students, int n) {
    int highestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].averageScore > students[highestIndex].averageScore) {
            highestIndex = i;
        }
    }
    return highestIndex;
}

void addStudent(Student* students, int* n, Student newStudent) {
    students[*n] = newStudent;
    (*n)++;
}

void deleteStudent(Student* students, int* n, char* studentID) {
    int index = findStudentByID(students, *n, studentID);
    if (index != -1) {
        for (int i = index; i < (*n) - 1; i++) {
            students[i] = students[i + 1];
        }
        (*n)--;
    }
    else {
        printf("Student ID not found.\n");
    }
}

void sortStudentsByAverageScore(Student* students, int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && students[i].averageScore > students[j].averageScore) ||
                (!ascending && students[i].averageScore < students[j].averageScore)) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void classifyStudent(Student* student) {
    if (student->averageScore >= 9.0) {
        printf("Student %s is classified as Excellent.\n", student->studentName);
    }
    else if (student->averageScore >= 8.0) {
        printf("Student %s is classified as Very Good.\n", student->studentName);
    }
    else if (student->averageScore >= 7.0) {
        printf("Student %s is classified as Good.\n", student->studentName);
    }
    else if (student->averageScore >= 6.0) {
        printf("Student %s is classified as Fair.\n", student->studentName);
    }
    else if (student->averageScore >= 5.0) {
        printf("Student %s is classified as Average.\n", student->studentName);
    }
    else {
        printf("Student %s is classified as Poor.\n", student->studentName);
    }
}

void countPassedFailedSubjects(Student* student) {
    int passed = 0, failed = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        if (student->subjects[i].score >= 5.0) {
            passed++;
        }
        else {
            failed++;
        }
    }
    printf("Student %s has passed %d subjects and failed %d subjects.\n",
        student->studentName, passed, failed);
}

