#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple_Module");
MODULE_AUTHOR("SGG");

struct _birthday {
 int day;
 int month;
 int year;
 struct list_head list;
};

static LIST_HEAD(birthday_list);

int simple_init(void) {
  printk(KERN_INFO "Loading Module !\n");
  printk(KERN_INFO "Creating birthday list\n");

  struct _birthday *person;
  person = kmalloc(sizeof(*person), GFP_KERNEL);
  person->day = 2;
  person->month = 8;
  person->year = 1995;
  INIT_LIST_HEAD(&person->list);
  list_add_tail(&person->list, &birthday_list);

  struct _birthday *melo;
  melo = kmalloc(sizeof(*melo), GFP_KERNEL);
  melo->day = 6;
  melo->month = 1;
  melo->year = 1988;
  INIT_LIST_HEAD(&melo->list);
  list_add_tail(&melo->list, &birthday_list);

  struct _birthday *arron;
  arron = kmalloc(sizeof(*arron), GFP_KERNEL);
  arron->day = 21;
  arron->month = 1;
  arron->year = 1998;
  INIT_LIST_HEAD(&arron->list);
  list_add_tail(&arron->list, &birthday_list);

  struct _birthday *tony;
  tony = kmalloc(sizeof(*tony), GFP_KERNEL);
  tony->day = 25;
  tony->month = 3;
  tony->year = 1997;
  INIT_LIST_HEAD(&tony->list);
  list_add_tail(&tony->list, &birthday_list);

  struct _birthday *taro;
  taro = kmalloc(sizeof(*taro), GFP_KERNEL);
  taro->day = 29;
  taro->month = 12;
  taro->year = 1968;
  INIT_LIST_HEAD(&taro->list);
  list_add_tail(&taro->list, &birthday_list);

  printk(KERN_INFO "Traversing the Linked List\n");

  struct _birthday *ptr;

  list_for_each_entry(ptr, &birthday_list, list) {
	  printk(KERN_INFO "Birthday: %d/ %d/ %d",ptr->month,ptr->day,ptr->year);
  }
  return 0;
}

static void simple_exit(void) {
 printk(KERN_INFO "Removing Module !\n");
 struct _birthday *ptr, *next;

 list_for_each_entry_safe(ptr, next, &birthday_list, list) {
  printk(KERN_INFO "Removing birthday: %d/ %d/ %d",ptr->month,ptr->day,ptr->year);
  list_del(&ptr->list);
  kfree(ptr);
 }
}

module_init(simple_init);
module_exit(simple_exit);
