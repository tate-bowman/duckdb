
#include "common/enums.hpp"
#include "common/exception.hpp"
#include "common/string_util.hpp"

using namespace std;

namespace duckdb {

ExpressionType StringToExpressionType(const string &str) {
	string upper_str = StringUtil::Upper(str);
	if (upper_str == "INVALID") {
		return ExpressionType::INVALID;
	} else if (upper_str == "OPERATOR_PLUS" || upper_str == "+") {
		return ExpressionType::OPERATOR_ADD;
	} else if (upper_str == "OPERATOR_MINUS" || upper_str == "-") {
		return ExpressionType::OPERATOR_SUBTRACT;
	} else if (upper_str == "OPERATOR_MULTIPLY" || upper_str == "*") {
		return ExpressionType::OPERATOR_MULTIPLY;
	} else if (upper_str == "OPERATOR_DIVIDE" || upper_str == "/") {
		return ExpressionType::OPERATOR_DIVIDE;
	} else if (upper_str == "OPERATOR_CONCAT" || upper_str == "||") {
		return ExpressionType::OPERATOR_CONCAT;
	} else if (upper_str == "OPERATOR_MOD" || upper_str == "%") {
		return ExpressionType::OPERATOR_MOD;
	} else if (upper_str == "OPERATOR_CAST") {
		return ExpressionType::OPERATOR_CAST;
	} else if (upper_str == "OPERATOR_NOT") {
		return ExpressionType::OPERATOR_NOT;
	} else if (upper_str == "OPERATOR_IS_NULL") {
		return ExpressionType::OPERATOR_IS_NULL;
	} else if (upper_str == "OPERATOR_EXISTS") {
		return ExpressionType::OPERATOR_EXISTS;
	} else if (upper_str == "COMPARE_EQUAL" || upper_str == "=") {
		return ExpressionType::COMPARE_EQUAL;
	} else if (upper_str == "COMPARE_NOTEQUAL" || upper_str == "!=" ||
	           upper_str == "<>") {
		return ExpressionType::COMPARE_NOTEQUAL;
	} else if (upper_str == "COMPARE_LESSTHAN" || upper_str == "<") {
		return ExpressionType::COMPARE_LESSTHAN;
	} else if (upper_str == "COMPARE_GREATERTHAN" || upper_str == ">") {
		return ExpressionType::COMPARE_GREATERTHAN;
	} else if (upper_str == "COMPARE_LESSTHANOREQUALTO" || upper_str == "<=") {
		return ExpressionType::COMPARE_LESSTHANOREQUALTO;
	} else if (upper_str == "COMPARE_GREATERTHANOREQUALTO" ||
	           upper_str == ">=") {
		return ExpressionType::COMPARE_GREATERTHANOREQUALTO;
	} else if (upper_str == "COMPARE_LIKE" || upper_str == "~~") {
		return ExpressionType::COMPARE_LIKE;
	} else if (upper_str == "COMPARE_NOTLIKE" || upper_str == "!~~") {
		return ExpressionType::COMPARE_NOTLIKE;
	} else if (upper_str == "COMPARE_IN") {
		return ExpressionType::COMPARE_IN;
	} else if (upper_str == "COMPARE_DISTINCT_FROM") {
		return ExpressionType::COMPARE_DISTINCT_FROM;
	} else if (upper_str == "CONJUNCTION_AND") {
		return ExpressionType::CONJUNCTION_AND;
	} else if (upper_str == "CONJUNCTION_OR") {
		return ExpressionType::CONJUNCTION_OR;
	} else if (upper_str == "VALUE_CONSTANT") {
		return ExpressionType::VALUE_CONSTANT;
	} else if (upper_str == "VALUE_PARAMETER") {
		return ExpressionType::VALUE_PARAMETER;
	} else if (upper_str == "VALUE_TUPLE") {
		return ExpressionType::VALUE_TUPLE;
	} else if (upper_str == "VALUE_TUPLE_ADDRESS") {
		return ExpressionType::VALUE_TUPLE_ADDRESS;
	} else if (upper_str == "VALUE_NULL") {
		return ExpressionType::VALUE_NULL;
	} else if (upper_str == "VALUE_VECTOR") {
		return ExpressionType::VALUE_VECTOR;
	} else if (upper_str == "VALUE_SCALAR") {
		return ExpressionType::VALUE_SCALAR;
	} else if (upper_str == "AGGREGATE_COUNT") {
		return ExpressionType::AGGREGATE_COUNT;
	} else if (upper_str == "AGGREGATE_COUNT_STAR") {
		return ExpressionType::AGGREGATE_COUNT_STAR;
	} else if (upper_str == "AGGREGATE_SUM") {
		return ExpressionType::AGGREGATE_SUM;
	} else if (upper_str == "AGGREGATE_MIN") {
		return ExpressionType::AGGREGATE_MIN;
	} else if (upper_str == "AGGREGATE_MAX") {
		return ExpressionType::AGGREGATE_MAX;
	} else if (upper_str == "AGGREGATE_AVG") {
		return ExpressionType::AGGREGATE_AVG;
	} else if (upper_str == "AGGREGATE_FIRST") {
		return ExpressionType::AGGREGATE_FIRST;
	} else if (upper_str == "FUNCTION") {
		return ExpressionType::FUNCTION;
	} else if (upper_str == "OPERATOR_CASE_EXPR") {
		return ExpressionType::OPERATOR_CASE_EXPR;
	} else if (upper_str == "OPERATOR_NULLIF") {
		return ExpressionType::OPERATOR_NULLIF;
	} else if (upper_str == "OPERATOR_COALESCE") {
		return ExpressionType::OPERATOR_COALESCE;
	} else if (upper_str == "ROW_SUBQUERY") {
		return ExpressionType::ROW_SUBQUERY;
	} else if (upper_str == "SELECT_SUBQUERY") {
		return ExpressionType::SELECT_SUBQUERY;
	} else if (upper_str == "STAR") {
		return ExpressionType::STAR;
	} else if (upper_str == "PLACEHOLDER") {
		return ExpressionType::PLACEHOLDER;
	} else if (upper_str == "COLUMN_REF") {
		return ExpressionType::COLUMN_REF;
	} else if (upper_str == "FUNCTION_REF") {
		return ExpressionType::FUNCTION_REF;
	} else if (upper_str == "CAST") {
		return ExpressionType::CAST;
	} else if (upper_str == "BETWEEN") {
		return ExpressionType::COMPARE_BETWEEN;
	} else if (upper_str == "NOT BETWEEN") {
		return ExpressionType::COMPARE_NOT_BETWEEN;
	}
	return ExpressionType::INVALID;
}

//===--------------------------------------------------------------------===//
// Value <--> String Utilities
//===--------------------------------------------------------------------===//

std::string TypeIdToString(TypeId type) {
	switch (type) {
	case TypeId::INVALID:
		return "INVALID";
	case TypeId::PARAMETER_OFFSET:
		return "PARAMETER_OFFSET";
	case TypeId::BOOLEAN:
		return "BOOLEAN";
	case TypeId::TINYINT:
		return "TINYINT";
	case TypeId::SMALLINT:
		return "SMALLINT";
	case TypeId::INTEGER:
		return "INTEGER";
	case TypeId::BIGINT:
		return "BIGINT";
	case TypeId::DECIMAL:
		return "DECIMAL";
	case TypeId::POINTER:
		return "POINTER";
	case TypeId::TIMESTAMP:
		return "TIMESTAMP";
	case TypeId::DATE:
		return "DATE";
	case TypeId::VARCHAR:
		return "VARCHAR";
	case TypeId::VARBINARY:
		return "VARBINARY";
	case TypeId::ARRAY:
		return "ARRAY";
	case TypeId::UDT:
		return "UDT";
	}
	return "INVALID";
}

string LogicalOperatorToString(LogicalOperatorType type) {
	switch (type) {
	case LogicalOperatorType::LEAF:
		return "LEAF";
	case LogicalOperatorType::GET:
		return "GET";
	case LogicalOperatorType::EXTERNAL_FILE_GET:
		return "EXTERNAL_FILE_GET";
	case LogicalOperatorType::QUERY_DERIVED_GET:
		return "QUERY_DERIVED_GET";
	case LogicalOperatorType::PROJECTION:
		return "PROJECTION";
	case LogicalOperatorType::FILTER:
		return "FILTER";
	case LogicalOperatorType::AGGREGATE_AND_GROUP_BY:
		return "AGGREGATE_AND_GROUP_BY";
	case LogicalOperatorType::LIMIT:
		return "LIMIT";
	case LogicalOperatorType::ORDER_BY:
		return "ORDER_BY";
	case LogicalOperatorType::COPY:
		return "COPY";
	case LogicalOperatorType::SUBQUERY:
		return "SUBQUERY";
	case LogicalOperatorType::JOIN:
		return "JOIN";
	case LogicalOperatorType::CROSS_PRODUCT:
		return "CROSS_PRODUCT";
	case LogicalOperatorType::UNION:
		return "UNION";
	case LogicalOperatorType::EXCEPT:
		return "EXCEPT";
	case LogicalOperatorType::INTERSECT:
		return "INTERSECT";
	case LogicalOperatorType::INSERT:
		return "INSERT";
	case LogicalOperatorType::INSERT_SELECT:
		return "INSERT_SELECT";
	case LogicalOperatorType::DELETE:
		return "DELETE";
	case LogicalOperatorType::UPDATE:
		return "UPDATE";
	case LogicalOperatorType::PRUNE_COLUMNS:
		return "PRUNE";
	case LogicalOperatorType::EXPORT_EXTERNAL_FILE:
		return "EXPORT_EXTERNAL_FILE";
	default:
		return "INVALID";
	}
}

string PhysicalOperatorToString(PhysicalOperatorType type) {
	switch (type) {
	case PhysicalOperatorType::LEAF:
		return "LEAF";
	case PhysicalOperatorType::DUMMY_SCAN:
		return "DUMMY_SCAN";
	case PhysicalOperatorType::SEQ_SCAN:
		return "SEQ_SCAN";
	case PhysicalOperatorType::INDEX_SCAN:
		return "INDEX_SCAN";
	case PhysicalOperatorType::EXTERNAL_FILE_SCAN:
		return "EXTERNAL_FILE_SCAN";
	case PhysicalOperatorType::QUERY_DERIVED_SCAN:
		return "QUERY_DERIVED_SCAN";
	case PhysicalOperatorType::ORDER_BY:
		return "ORDER_BY";
	case PhysicalOperatorType::LIMIT:
		return "LIMIT";
	case PhysicalOperatorType::AGGREGATE:
		return "AGGREGATE";
	case PhysicalOperatorType::HASH_GROUP_BY:
		return "HASH_GROUP_BY";
	case PhysicalOperatorType::SORT_GROUP_BY:
		return "SORT_GROUP_BY";
	case PhysicalOperatorType::FILTER:
		return "FILTER";
	case PhysicalOperatorType::PROJECTION:
		return "PROJECTION";
	case PhysicalOperatorType::BASE_GROUP_BY:
		return "BASE_GROUP_BY";
	case PhysicalOperatorType::COPY:
		return "COPY";
	case PhysicalOperatorType::NESTED_LOOP_JOIN:
		return "NESTED_LOOP_JOIN";
	case PhysicalOperatorType::HASH_JOIN:
		return "HASH_JOIN";
	case PhysicalOperatorType::PIECEWISE_MERGE_JOIN:
		return "PIECEWISE_MERGE_JOIN";
	case PhysicalOperatorType::CROSS_PRODUCT:
		return "CROSS_PRODUCT";
	case PhysicalOperatorType::UNION:
		return "UNION";
	case PhysicalOperatorType::INSERT:
		return "INSERT";
	case PhysicalOperatorType::INSERT_SELECT:
		return "INSERT_SELECT";
	case PhysicalOperatorType::DELETE:
		return "DELETE";
	case PhysicalOperatorType::UPDATE:
		return "UPDATE";
	case PhysicalOperatorType::EXPORT_EXTERNAL_FILE:
		return "EXPORT_EXTERNAL_FILE";
	case PhysicalOperatorType::PRUNE_COLUMNS:
		return "PRUNE";
	default:
		return "INVALID";
	}
}

string ExpressionTypeToString(ExpressionType type) {
	switch (type) {
	case ExpressionType::INVALID:
		return "INVALID";
	case ExpressionType::OPERATOR_ADD:
		return "ADD";
	case ExpressionType::OPERATOR_SUBTRACT:
		return "SUBTRACT";
	case ExpressionType::OPERATOR_MULTIPLY:
		return "MULTIPLY";
	case ExpressionType::OPERATOR_DIVIDE:
		return "DIVIDE";
	case ExpressionType::OPERATOR_CONCAT:
		return "CONCAT";
	case ExpressionType::OPERATOR_MOD:
		return "MOD";
	case ExpressionType::OPERATOR_CAST:
		return "CAST";
	case ExpressionType::OPERATOR_NOT:
		return "NOT";
	case ExpressionType::OPERATOR_IS_NULL:
		return "IS_NULL";
	case ExpressionType::OPERATOR_IS_NOT_NULL:
		return "IS_NOT_NULL";
	case ExpressionType::OPERATOR_EXISTS:
		return "EXISTS";
	case ExpressionType::COMPARE_EQUAL:
		return "EQUAL";
	case ExpressionType::COMPARE_NOTEQUAL:
		return "NOTEQUAL";
	case ExpressionType::COMPARE_LESSTHAN:
		return "LESSTHAN";
	case ExpressionType::COMPARE_GREATERTHAN:
		return "GREATERTHAN";
	case ExpressionType::COMPARE_LESSTHANOREQUALTO:
		return "LESSTHANOREQUALTO";
	case ExpressionType::COMPARE_GREATERTHANOREQUALTO:
		return "GREATERTHANOREQUALTO";
	case ExpressionType::COMPARE_LIKE:
		return "LIKE";
	case ExpressionType::COMPARE_NOTLIKE:
		return "NOTLIKE";
	case ExpressionType::COMPARE_IN:
		return "IN";
	case ExpressionType::COMPARE_DISTINCT_FROM:
		return "DISTINCT_FROM";
	case ExpressionType::CONJUNCTION_AND:
		return "AND";
	case ExpressionType::CONJUNCTION_OR:
		return "OR";
	case ExpressionType::VALUE_CONSTANT:
		return "CONSTANT";
	case ExpressionType::VALUE_PARAMETER:
		return "PARAMETER";
	case ExpressionType::VALUE_TUPLE:
		return "TUPLE";
	case ExpressionType::VALUE_TUPLE_ADDRESS:
		return "TUPLE_ADDRESS";
	case ExpressionType::VALUE_NULL:
		return "NULL";
	case ExpressionType::VALUE_VECTOR:
		return "VECTOR";
	case ExpressionType::VALUE_SCALAR:
		return "SCALAR";
	case ExpressionType::AGGREGATE_COUNT:
		return "COUNT";
	case ExpressionType::AGGREGATE_COUNT_STAR:
		return "COUNT_STAR";
	case ExpressionType::AGGREGATE_COUNT_DISTINCT:
		return "COUNT_DISTINCT";
	case ExpressionType::AGGREGATE_SUM:
		return "SUM";
	case ExpressionType::AGGREGATE_SUM_DISTINCT:
		return "SUM_DISTINCT";
	case ExpressionType::AGGREGATE_MIN:
		return "MIN";
	case ExpressionType::AGGREGATE_MAX:
		return "MAX";
	case ExpressionType::AGGREGATE_AVG:
		return "AVG";
	case ExpressionType::AGGREGATE_FIRST:
		return "FIRST";
	case ExpressionType::FUNCTION:
		return "FUNCTION";
	case ExpressionType::OPERATOR_CASE_EXPR:
		return "CASE";
	case ExpressionType::OPERATOR_NULLIF:
		return "NULLIF";
	case ExpressionType::OPERATOR_COALESCE:
		return "COALESCE";
	case ExpressionType::ROW_SUBQUERY:
		return "SUBQUERY";
	case ExpressionType::SELECT_SUBQUERY:
		return "SUBQUERY";
	case ExpressionType::STAR:
		return "STAR";
	case ExpressionType::PLACEHOLDER:
		return "PLACEHOLDER";
	case ExpressionType::COLUMN_REF:
		return "COLUMN_REF";
	case ExpressionType::FUNCTION_REF:
		return "FUNCTION_REF";
	case ExpressionType::TABLE_REF:
		return "TABLE_REF";
	case ExpressionType::GROUP_REF:
		return "GROUP_REF";
	case ExpressionType::CAST:
		return "CAST";
	default:
		return "UKNOWN_EXP_" + std::to_string((int)type);
	}
}

string ExpressionTypeToOperator(ExpressionType type) {
	switch (type) {
	case ExpressionType::OPERATOR_ADD:
		return "+";
	case ExpressionType::OPERATOR_SUBTRACT:
		return "-";
	case ExpressionType::OPERATOR_MULTIPLY:
		return "*";
	case ExpressionType::OPERATOR_DIVIDE:
		return "/";
	case ExpressionType::OPERATOR_CONCAT:
		return "+";
	case ExpressionType::OPERATOR_MOD:
		return "%";
	case ExpressionType::OPERATOR_NOT:
		return "!";
	case ExpressionType::COMPARE_EQUAL:
		return "=";
	case ExpressionType::COMPARE_NOTEQUAL:
		return "!=";
	case ExpressionType::COMPARE_LESSTHAN:
		return "<";
	case ExpressionType::COMPARE_GREATERTHAN:
		return ">";
	case ExpressionType::COMPARE_LESSTHANOREQUALTO:
		return "<=";
	case ExpressionType::COMPARE_GREATERTHANOREQUALTO:
		return ">=";
	case ExpressionType::STAR:
		return "*";
	default:
		return "";
	}
}

string JoinTypeToString(JoinType type) {
	switch (type) {
	case JoinType::LEFT:
		return "LEFT";
	case JoinType::RIGHT:
		return "RIGHT";
	case JoinType::INNER:
		return "INNER";
	case JoinType::OUTER:
		return "OUTER";
	case JoinType::SEMI:
		return "SEMI";
	case JoinType::ANTI:
		return "ANTI";
	default:
		return "INVALID";
	}
}

ExternalFileFormat StringToExternalFileFormat(const std::string &str) {
	auto upper = StringUtil::Upper(str);
	if (upper == "CSV") {
		return ExternalFileFormat::CSV;
	}
	throw ConversionException("No ExternalFileFormat for input '%s'",
	                          upper.c_str());
}

IndexType StringToIndexType(const std::string &str) {
	std::string upper_str = StringUtil::Upper(str);
	if (upper_str == "INVALID") {
		return IndexType::INVALID;
	} else if (upper_str == "BTREE") {
		return IndexType::BTREE;
	} else {
		throw ConversionException(StringUtil::Format(
		    "No IndexType conversion from string '%s'", upper_str.c_str()));
	}
	return IndexType::INVALID;
}

} // namespace duckdb