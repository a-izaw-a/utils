#ifndef FIFO_H_
#define FIFO_H_

/* secure FINI FList spaces */
#define FINI	16

/* FIFO構造をもつlist */
typedef struct FIFO{
  void		*contents;
  struct FIFO	*newer;
  struct FIFO	*older;
  struct FIFO	*space;
}FList;

/* Initialize FList */
extern FList	*FInit(void);

/* Secure FList memory space, in advance */
extern void	FSec(FList *header);

/* add new element */
extern void	FPush(FList *header, void *target);

/* get oldest element */
extern void	*FPop(FList *header);

/*****************************************
 * delete newest element equal to target *
 * 0:false 1:success			 *
 *****************************************/
extern int	FDel(FList *header, void *target);

/***********************
 * define compare rule *
 * 0:unequal 1:equal   *
 ***********************/
extern int	FCompare(FList *header, void *target);

extern FList	*FGetSpace(FList *header);
#endif
