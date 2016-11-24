#ifndef __PART3_LIST_H__
#define __PART3_LIST_H__

typedef int ElementType;

typedef struct _NODE_T
{
    ElementType element;
    struct _NODE_T *next;
}NODE_T;

typedef struct _NODE_T * LINK_LIST_T;
typedef struct _NODE_T * POSITION;


#define LISTR_OK                              ((INT32)0)
#define LISTR_FAIL                            ((INT32)-1)

#define LINK_LIST_CHK_FAIL(argu, value)     if(!(argu)) {printf("<LINK_LIST> ERR : func=%s, line=%d, argument="#argu".\n", __func__, __LINE__); return value;}



extern LINK_LIST_T link_list_init(VOID);
extern BOOL link_list_is_empty(LINK_LIST_T pList);
extern BOOL link_list_is_last(ElementType element, LINK_LIST_T pList);
extern BOOL link_list_find_element(ElementType element, LINK_LIST_T pList);
extern INT32 link_list_find_element_ret_index(ElementType element, LINK_LIST_T pList);
extern BOOL link_list_find_by_index(ElementType *element, INT32 index, LINK_LIST_T pList);
extern POSITION link_list_find_previous(ElementType element, LINK_LIST_T pList);
extern INT32 link_list_insert_at_tail(ElementType element, LINK_LIST_T pList);
extern INT32 link_list_insert_at_head(ElementType element, LINK_LIST_T pList);
extern INT32 link_list_insert_by_index(ElementType element, INT32 index, LINK_LIST_T pList);
extern INT32 link_list_delete_by_index(ElementType *element, INT32 index, LINK_LIST_T pList);
extern INT32 link_list_get_list_len(LINK_LIST_T pList);
extern INT32 link_list_uninit(LINK_LIST_T pList);
extern VOID link_list_traverse(LINK_LIST_T pList);
extern VOID link_list_main_test(VOID);

#endif