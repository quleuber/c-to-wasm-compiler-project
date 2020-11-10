#if !defined(DECLARATIONS_H)
#define DECLARATIONS_H

#include <string>
#include <vector>

#include "types.hpp"

namespace decl {

struct DeclarationSpec {
    /** Força a classe a ser polimórfica */
    virtual ~DeclarationSpec() = default;
};

struct StorageClassSpec : DeclarationSpec {
    enum Kind {
        TYPEDEF,
        EXTERN,
        STATIC,
        AUTO,
        REGISTER,
    };
    StorageClassSpec(const Kind kind) : kind(kind) {}
    const Kind kind;
};

using types::TypeQualOrTypeSpecPointer;
struct TypeDeclSpec : DeclarationSpec {
    TypeDeclSpec(const TypeQualOrTypeSpecPointer value) { this->value = value; }
    TypeQualOrTypeSpecPointer get() const { return this->value; }
  protected:
    types::TypeQualOrTypeSpecPointer value;
};

struct DeclarationSpecs : std::vector<DeclarationSpec*> {
    void add(DeclarationSpec* spec) { this->push_back(spec); }
};

struct InitDeclarators : std::vector<std::string*> {
    void add(std::string* init) { this->push_back(init); }
};

void declare(const DeclarationSpecs& specs, const InitDeclarators& decls);

}; // namespace decl

#endif /* DECLARATIONS_H */
