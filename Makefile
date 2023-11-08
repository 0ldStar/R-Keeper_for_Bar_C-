CC=g++
CFLAGS=-I/opt/homebrew/Cellar/libpq/16.0/include/
CFLAGS+=-I./DataClasses/Employee/
CFLAGS+=-I./DataClasses/Transfer/
CFLAGS+=-I./DataClasses/Drink/
CFLAGS+=-I./DataClasses/Snack/
CFLAGS+=-I./DataClasses/Recipe/
CFLAGS+=-I./DataClasses/Assortment/
CFLAGS+=-I./DataClasses/Product/
CFLAGS+=-I./DataClasses/BankDetails/
CFLAGS+=-I./DataClasses/Ingredient/
CFLAGS+=-I./DataClasses/Supplier/
CFLAGS+=-I./DB/
CFLAGS+=-I./Menu/

CFLAGS+=-L/opt/homebrew/Cellar/libpq/16.0/lib/
CFLAGS+=-Wall -Wextra -std=c++20

LDFLAGS=-lpq -lpthread 

SRCS=main.cpp 
SRCS+=DB/DBConnection.cpp DB/DefaultTables.cpp 
SRCS+= DataClasses/Employee/Employee.cpp DataClasses/Employee/EmployeeMapper.cpp 
SRCS+= DataClasses/Transfer/Transfer.cpp DataClasses/Transfer/TransferMapper.cpp
SRCS+= DataClasses/Drink/Drink.cpp DataClasses/Drink/DrinkMapper.cpp
SRCS+= DataClasses/Snack/Snack.cpp DataClasses/Snack/SnackMapper.cpp
SRCS+= DataClasses/Recipe/Recipe.cpp DataClasses/Recipe/RecipeMapper.cpp
SRCS+= DataClasses/Assortment/Assortment.cpp DataClasses/Assortment/AssortmentMapper.cpp
SRCS+= DataClasses/Product/Product.cpp DataClasses/Product/ProductMapper.cpp
SRCS+= DataClasses/BankDetails/BankDetails.cpp DataClasses/BankDetails/BankDetailsMapper.cpp
SRCS+= DataClasses/Ingredient/Ingredient.cpp DataClasses/Ingredient/IngredientMapper.cpp
SRCS+= DataClasses/Supplier/Supplier.cpp DataClasses/Supplier/SupplierMapper.cpp
SRCS+= Menu/barMenu.cpp Menu/employeeMenu.cpp Menu/supplierMenu.cpp

OBJS=$(SRCS:.cpp=.o)

all: lab1

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

lab1: $(SRCS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

clean:
	rm -rf *.o ./*/*.o ./*/*/*.o lab1