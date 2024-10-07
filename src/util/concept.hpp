#pragma once

template <typename T, typename... Types>
concept is_all_same = (... && std::is_same<T, Types>::value);
