#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
  // TODO - you fill in here.

  // make sure the lists are not empty
  if(L1 == NULL && L2 == NULL){
    return NULL;
  }
  if(L1 == NULL){
    return L2;
  }
  if(L2 == NULL){
    return L1;
  }

  shared_ptr<ListNode<int>> head = NULL;
  // assign head
  if(L1->data <= L2->data){
    head = L1;
    L1 = L1->next;
  } else{
    head = L2;
    L2 = L2->next;
  }
  shared_ptr<ListNode<int>> curr = head;

  // compare each element
  while(L1 != NULL && L2 != NULL){
  
    if(L1->data <= L2->data){
      curr->next = L1;
      L1 = L1->next;
    }
    else{
      curr->next = L2;
      L2 = L2->next;
    }
    curr = curr->next;
  }

  // if one of list is empty reassign other list
  if(L1 == NULL){
    curr->next = L2;
  }else{
    curr->next = L1;
  }

  return head;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "sorted_lists_merge.cc",
                         "sorted_lists_merge.tsv", &MergeTwoSortedLists,
                         DefaultComparator{}, param_names);
}
