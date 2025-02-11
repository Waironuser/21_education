#ifndef S21_DECIMAL_TYPES_ENUMS_H
#define S21_DECIMAL_TYPES_ENUMS_H

// Перечисление/наименование каждой секции битов, для лучшей читаемости
enum decimal_int_bits { LOW = 0, MIDDLE = 1, HIGH = 2, INFO = 3 };

// Перечисление/наименование каждой секции битов внутри bits[3], для лучшей
// читаемости
enum decimal_info_bits {
  UNUSED_LOWER = 0,
  POWER = 1,
  UNUSED_HIGHER = 2,
  SIGN = 3
};

#endif