    // Example 2
    ListNode *listA2 = new ListNode(1);
    listA2->next = new ListNode(9);
    listA2->next->next = new ListNode(1);
    listA2->next->next->next = new ListNode(2);
    listA2->next->next->next->next = new ListNode(4);

    ListNode *listB2 = new ListNode(3);
    listB2->next = new ListNode(2);
    listB2->next->next = new ListNode(4);

    cout << "\nList A: ";
    displayList(listA2);
    cout << "List B: ";
    displayList(listB2);

    ListNode *intersectionNode2 = solution.getIntersectionNode(listA2, listB2);

    if (intersectionNode2 != nullptr)
        cout << "Intersection Node Value: " << intersectionNode2->val << endl;
    else
        cout << "No Intersection" << endl;