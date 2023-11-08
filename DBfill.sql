BEGIN;
INSERT INTO "employees" ("name", "address", "date_of_birth", "position", "salary")
VALUES
  ('John Doe', '123 Main St', '1990-05-15', 'Manager', 60000),
  ('Jane Smith', '456 Elm St', '1985-08-20', 'Developer', 55000),
  ('Bob Johnson', '789 Oak St', '1995-02-10', 'Salesperson', 45000),
  ('Alice Brown', '101 Pine St', '1988-11-30', 'Designer', 52000),
  ('Chris Wilson', '202 Cedar St', '1992-04-25', 'Engineer', 58000);

INSERT INTO "transfers" ("employee_id", "position", "reason", "number_of_order", "date_of_order")
VALUES
  (1, 'Manager', 'Promotion', 1001, '2023-10-10'),
  (2, 'Developer', 'New Hire', 1002, '2023-10-12'),
  (3, 'Salesperson', 'Transfer', 1003, '2023-10-15'),
  (4, 'Designer', 'Promotion', 1004, '2023-10-18'),
  (5, 'Engineer', 'New Hire', 1005, '2023-10-20');

INSERT INTO "drinks" ("name", "portion_size", "capacity")
VALUES
  ('Negroni', 12, 'glass'),
  ('IPA', 10, 'glass for beer'),
  ('Whisky', 16, 'shot'),
  ('Rum', 8, 'shot'),
  ('Wine', 20, 'glass for wine');

INSERT INTO "ingredients" ("product_id", "quantity", "unit_of_measurement")
VALUES
  (1, 100, 'grams'),
  (2, 200, 'grams'),
  (3, 2, 'cans'),
  (4, 500, 'ml'),
  (5, 1, 'bottle');

INSERT INTO "drinks_recipes" ("drink_id", "ingredient_id")
VALUES
  (1, 1),
  (1, 2),
  (3, 3),
  (4, 4),
  (5, 5);

INSERT INTO "snacks" ("name", "size_of_portions")
VALUES
  ('Chips', 50),
  ('Pretzels', 60),
  ('Popcorn', 75),
  ('Nuts', 40),
  ('Candy', 30);

INSERT INTO "suppliers" ("name", "post_address", "phone_number", "fax_number", "email")
VALUES
  ('Supplier A', '123 Supplier St', '+1234567890', '+1234567891', 'supplierA@example.com'),
  ('Supplier B', '456 Supplier St', '+9876543210', '+9876543211', 'supplierB@example.com'),
  ('Supplier C', '789 Supplier St', '+5678901234', '+5678901235', 'supplierC@example.com'),
  ('Supplier D', '101 Supplier St', '+4321098765', '+4321098766', 'supplierD@example.com'),
  ('Supplier E', '202 Supplier St', '+6543210987', '+6543210988', 'supplierE@example.com');

INSERT INTO "bank_details" ("supplier_id", "name", "city", "tin", "settlement_account")
VALUES
  (1, 'Bank A', 'City A', '123456789', '12345678-901'),
  (2, 'Bank B', 'City B', '987654321', '98765432-101'),
  (3, 'Bank C', 'City C', '567890123', '56789012-345'),
  (4, 'Bank D', 'City D', '432109876', '43210987-654'),
  (5, 'Bank E', 'City E', '654321098', '65432109-876');

INSERT INTO "assortments" ("supplier_id", "wholesale_price", "delivery_terms", "payment_terms")
VALUES
  (1, 100.00, 'Fast Delivery', 'Net 30 Days'),
  (2, 90.00, 'Standard Delivery', 'Net 45 Days'),
  (3, 110.00, 'Express Delivery', 'Net 60 Days'),
  (4, 95.00, 'Standard Delivery', 'Net 30 Days'),
  (5, 120.00, 'Fast Delivery', 'Net 45 Days');

INSERT INTO "products" ("name")
VALUES
  ('Product 1'),
  ('Product 2'),
  ('Product 3'),
  ('Product 4'),
  ('Product 5');

INSERT INTO "product_assortment" ("assortment_id", "product_id")
VALUES
  (1, 1),
  (2, 2),
  (3, 3),
  (4, 4),
  (5, 5);

INSERT INTO "snacks_recipes" ("snack_id", "ingredient_id")
VALUES
  (1, 1),
  (1, 2),
  (3, 3),
  (4, 4),
  (5, 5);
COMMIT;