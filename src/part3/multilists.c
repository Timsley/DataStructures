#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NAME_LEN 10


/* Assume there have three Courses and four Students */
typedef enum
{
    CHINESE = 1,              
    ENGLISH,
    MATH,                   
}e_COURSE_TYPE;

#define STUA    "Tom"
#define STUB    "Mary"
#define STUC    "Jake"
#define STUD    "Ray"


typedef struct _Node_T
{
    char name[NAME_LEN];
    e_COURSE_TYPE course;   	
    struct _Node_T *next;	
}Node;

typedef struct _Node_T * Head;

struct _Node_T * StuA;
struct _Node_T * StuB;
struct _Node_T * StuC;
struct _Node_T * StuD;
struct _Node_T * CourseCH;
struct _Node_T * CourseEN;
struct _Node_T * CourseMA;


Node * multi_lists_make_node(void)
{
    Node  * node = (Node *)malloc(sizeof(Node));
    if(NULL == node)
    {
        printf("node malloc fail!\n");
        return NULL;
    }
    memset(node, 0, sizeof(Node));
    
    memset(node->name, 0, sizeof(char)*NAME_LEN);
    node->course = 0;
    node->next = NULL;

    return node;
}

void multi_lists_init(void)
{
    StuA = multi_lists_make_node();
    strcpy(StuA->name, STUA);
    StuB = multi_lists_make_node();
    strcpy(StuB->name, STUB);
    StuC = multi_lists_make_node();
    strcpy(StuC->name, STUC);
    StuD = multi_lists_make_node();
    strcpy(StuD->name, STUD);
    
    CourseCH = multi_lists_make_node();
    CourseCH->course = CHINESE;
    CourseEN = multi_lists_make_node();
    CourseEN->course = ENGLISH;
    CourseMA = multi_lists_make_node();
    CourseMA->course = MATH;
}

/* Get the head pointer of the Student */
Head multi_lists_get_head_by_name(char * student)
{
    if( (NULL != StuA) && (0 == strcmp(StuA->name, student)) )
    {
        return StuA;
    }
    
    if( (NULL != StuB) && (0 == strcmp(StuB->name, student)) )
    {
        return StuB;
    }
    
    if( (NULL != StuC) && (0 == strcmp(StuC->name, student)) )
    {
        return StuC;
    }
    
    if( (NULL != StuD) && (0 == strcmp(StuD->name, student)) )
    {
        return StuD;
    }

    return NULL;
}

/* Get the head pointer of the Course */
Head multi_lists_get_head_by_course(e_COURSE_TYPE course)
{
    if( (NULL != CourseCH) && (CourseCH->course == course) )
    {
        return CourseCH;
    }
    
    if( (NULL != CourseEN) && (CourseEN->course == course) )
    {
        return CourseEN;
    }
    
    if( (NULL != CourseMA) && (CourseMA->course == course) )
    {
        return CourseMA;
    }

    return NULL;
}

/* Judge Function : If Student choose the same Course, it will return true */
bool multi_lists_same_course(Node * pStu, e_COURSE_TYPE course)
{
    Node * pTemp = pStu;

    while(pTemp->next)
    {
        if(pTemp->next->course == course)
            return true;

        pTemp = pTemp->next;
    }

    return false;
}

/* Judge Function : If the Course have the same Student, it will return true */
bool multi_lists_same_student(Node * pCour, char * student)
{
    Node * pTemp = pCour;

    while(pTemp->next)
    {
        if(0 == strcmp(pCour->next->name, student))
            return true;

        pTemp = pTemp->next;
    }

    return false;
}

/* Register the Course and the Student */
void multi_lists_course_register(char *student, e_COURSE_TYPE course)
{
    Node * pStu = multi_lists_get_head_by_name(student);
    if(NULL == pStu)
    {
        printf("No this student, ignore it\n");
        return;
    }

    /* Ignoe the student register the same course */
    if(false == multi_lists_same_course(pStu, course))
    {
        // insert node of the front the list
        Node * newCourse = multi_lists_make_node();
        newCourse->course = course;
        newCourse->next = pStu->next;

        pStu->next = newCourse;
    }

    Node * pCour = multi_lists_get_head_by_course(course);
    if(NULL == pCour)
    {
        printf("No this Course, ignore it\n");
        return;
    }

    /* Ignore the Course register the same student */
    if(false == multi_lists_same_student(pCour, student))
    {        
        // insert node of the front the list
        Node * newStu = multi_lists_make_node();
        strcpy(newStu->name, student);
        newStu->next = pCour->next;
        
        pCour->next = newStu;  
    }
}

/* Unregister the Course and the Student */
void multi_lists_course_unregister(char *student, e_COURSE_TYPE course)
{
    Node * pStu = multi_lists_get_head_by_name(student);
    if(NULL == pStu)
    {
        printf("No this student, ignore it\n");
        return;
    }

    Node * pCour = multi_lists_get_head_by_course(course);
    if(NULL == pCour)
    {
        printf("No this Course, ignore it\n");
        return;
    }

    Node * pTemp = NULL;
    
    /* free the Course Node from the Student List */
    while(pStu->next)
    {
        if(pStu->next->course == course)
        {
            pTemp = pStu->next;
            pStu->next = pTemp->next;
            free(pTemp);
            break;
        }
        pStu = pStu->next;
    }
    
    /* free the Student Node from the Course List */
    while(pCour->next)
    {
        if(0 == strcmp(pCour->next->name, student) )
        {
            pTemp = pCour->next;
            pCour->next = pTemp->next;
            free(pTemp);
            break;
        }
        pCour = pCour->next;
    }
}

void multi_lists_print_format(e_COURSE_TYPE course)
{
    if(CHINESE == course)
        printf("%-7s ", "Chinese");
    else if(ENGLISH == course)
        printf("%-7s ", "English");
    else if(MATH == course)
        printf("%-7s ", "Math");
}

/* print the student choose which course */
void multi_lists_traverse_stu(char *student)
{
    Node * pStu = multi_lists_get_head_by_name(student);
    if(NULL == pStu)
    {
        printf("No this student, ignore it\n");
        return;
    }

    printf("%5s choose Course : ", student);

    while(pStu->next)
    {
        multi_lists_print_format(pStu->next->course);
        pStu = pStu->next;
    }
    
    printf("\n");
}

/* print who is in the course */
void multi_lists_traverse_course(e_COURSE_TYPE course)
{
    Node * pCour = multi_lists_get_head_by_course(course);
    if(NULL == pCour)
    {
        printf("No this Course, ignore it\n");
        return;
    }
    
    printf("Course( ");
    multi_lists_print_format(course);
    printf(")have students : ");

    while(pCour->next)
    {
        printf("%s  ", pCour->next->name);
        pCour = pCour->next;
    }

    printf("\n");
}

/* Test Function */
void multi_lists_main_test(void)
{
    multi_lists_init();

    multi_lists_course_register(STUA, CHINESE);
    multi_lists_course_register(STUA, ENGLISH);
    multi_lists_course_register(STUA, MATH);
    multi_lists_course_register(STUB, CHINESE);
    multi_lists_course_register(STUB, MATH);
    multi_lists_course_register(STUC, CHINESE);

    multi_lists_course_unregister(STUA, ENGLISH);
    multi_lists_course_unregister(STUB, MATH);

    multi_lists_traverse_stu(STUA);
    multi_lists_traverse_stu(STUB);

    multi_lists_traverse_course(CHINESE);
    multi_lists_traverse_course(MATH);
}
