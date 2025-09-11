#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct Node {
    int coeff;
    int power;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into polynomial (at end)
struct Node* insert(struct Node* head, int coeff, int power) {
    struct Node* newNode = createNode(coeff, power);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to display polynomial
void display(struct Node* head) {
    if (head == NULL) {
        printf("0");
        return;
    }

    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->power);
        head = head->next;
        if (head != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->power == p2->power) {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                result = insert(result, sum, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->power > p2->power) {
            result = insert(result, p1->coeff, p1->power);
            p1 = p1->next;
        }
        else {
            result = insert(result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }

    // Copy remaining terms
    while (p1 != NULL) {
        result = insert(result, p1->coeff, p1->power);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insert(result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

// Main function
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    int n, coeff, power;

    // Input first polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter terms (coefficient power) in descending order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &power);
        poly1 = insert(poly1, coeff, power);
    }

    // Input second polynomial
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter terms (coefficient power) in descending order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &power);
        poly2 = insert(poly2, coeff, power);
    }

    // Display input polynomials
    printf("\nFirst Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);

    // Add polynomials
    result = addPolynomials(poly1, poly2);

    // Display result
    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}
