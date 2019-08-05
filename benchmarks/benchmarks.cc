#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch.hpp>

#include "quantum_basis.h"
#include "quantum_circuit.h"
#include "quantum_computer.h"
#include "quantum_gate.h"

QuantumBasis qb;

// QuantumComputer qc_4(4);
// QuantumComputer qc_8(8);
// QuantumComputer qc_16(16);
// QuantumComputer qc_18(18);

QuantumCircuit qcirc_4;
QuantumCircuit qcirc_8;
QuantumCircuit qcirc_16;
QuantumCircuit qcirc_18;

QuantumCircuit qcirc2_4;
QuantumCircuit qcirc2_8;
QuantumCircuit qcirc2_16;
QuantumCircuit qcirc2_18;

std::vector<QuantumComputer> computers;

void prepare_circ(QuantumCircuit& qcirc, size_t start, size_t end) {
    for (size_t i = start; i < end; i++) {
        qcirc.add_gate(make_gate("H", i, i));
        //        qcirc.add_gate(make_gate("Y", i, i));
        //        qcirc.add_gate(make_gate("Y", i, i));
    }
}

void prepare_circ2(QuantumCircuit& qcirc, size_t start, size_t end) {
    for (size_t i = start; i < end; i++) {
        qcirc.add_gate(make_gate("X", i, i));
        qcirc.add_gate(make_gate("Y", i, i));
        qcirc.add_gate(make_gate("Z", i, i));
    }
}

TEST_CASE("QuantumComputer", "[benchmark]") {
    prepare_circ(qcirc_4, 0, 4);
    prepare_circ(qcirc_8, 0, 8);
    prepare_circ(qcirc_16, 0, 16);
    prepare_circ(qcirc_18, 0, 18);

    prepare_circ2(qcirc2_4, 0, 4);
    prepare_circ2(qcirc2_8, 0, 8);
    prepare_circ2(qcirc2_16, 0, 16);
    prepare_circ2(qcirc2_18, 0, 18);

    QuantumComputer qc1_4(4);
    QuantumComputer qc1_8(8);
    QuantumComputer qc1_16(16);
    QuantumComputer qc1_18(18);

    //    BENCHMARK("qc_4_apply_circuit") { qc_4.apply_circuit(qcirc_4); };

    // BENCHMARK("qc_8_apply_circuit") { qc_8.apply_circuit(qcirc_8); };

    // BENCHMARK("qc_16_apply_circuit") { qc_16.apply_circuit(qcirc_16); };

    BENCHMARK("qc_18_apply_circuit") { qc1_18.apply_circuit(qcirc_18); };

    QuantumComputer qc2_4(4);
    QuantumComputer qc2_8(8);
    QuantumComputer qc2_16(16);
    QuantumComputer qc2_18(18);

    //    BENCHMARK("qc_4_apply_circuit_fast") { qc_4.apply_circuit_fast(qcirc_4); };

    // BENCHMARK("qc_8_apply_circuit_fast") { qc_8.apply_circuit_fast(qcirc_8); };

    // BENCHMARK("qc_16_apply_circuit_fast") { qc_16.apply_circuit_fast(qcirc_16); };

    BENCHMARK("qc_18_apply_circuit_fast") { qc2_18.apply_circuit_fast(qcirc_18); };

    QuantumComputer qc3_4(4);
    QuantumComputer qc3_8(8);
    QuantumComputer qc3_16(16);
    QuantumComputer qc3_18(18);

    //    BENCHMARK("qc_4_apply_circuit_fast2") { qc_4.apply_circuit_fast2(qcirc_4); };

    // BENCHMARK("qc_8_apply_circuit_fast2") { qc_8.apply_circuit_fast2(qcirc_8); };

    // BENCHMARK("qc_16_apply_circuit_fast2") { qc_16.apply_circuit_fast2(qcirc_16); };

    BENCHMARK("qc_18_apply_circuit_fast2") { qc3_18.apply_circuit_fast2(qcirc_18); };

    QuantumComputer qc4_4(4);
    QuantumComputer qc4_8(8);
    QuantumComputer qc4_16(16);
    QuantumComputer qc4_18(18);


        //    BENCHMARK("qc_4_apply_circuit2") { qc_4.apply_circuit2(qcirc2_4); };

    // BENCHMARK("qc_8_apply_circuit2") { qc_8.apply_circuit(qcirc2_8); };

    // BENCHMARK("qc_16_apply_circuit2") { qc_16.apply_circuit(qcirc2_16); };

    BENCHMARK("qc_18_apply_circuit2") { qc4_18.apply_circuit(qcirc2_18); };

    QuantumComputer qc5_4(4);
    QuantumComputer qc5_8(8);
    QuantumComputer qc5_16(16);
    QuantumComputer qc5_18(18);

    //    BENCHMARK("qc_4_apply_circuit2_fast") { qc_4.apply_circuit2_fast(qcirc2_4); };

    // BENCHMARK("qc_8_apply_circuit2_fast") { qc_8.apply_circuit_fast(qcirc2_8); };

    // BENCHMARK("qc_16_apply_circuit2_fast") { qc_16.apply_circuit_fast(qcirc2_16); };

    BENCHMARK("qc_18_apply_circuit2_fast") { qc5_18.apply_circuit_fast(qcirc2_18); };

    QuantumComputer qc6_4(4);
    QuantumComputer qc6_8(8);
    QuantumComputer qc6_16(16);
    QuantumComputer qc6_18(18);

    //    BENCHMARK("qc_4_apply_circuit2_fast2") { qc_4.apply_circuit2_fast2(qcirc2_4); };

    // BENCHMARK("qc_8_apply_circuit2_fast2") { qc_8.apply_circuit_fast2(qcirc2_8); };

    // BENCHMARK("qc_16_apply_circuit2_fast2") { qc_16.apply_circuit_fast2(qcirc2_16); };

    BENCHMARK("qc_18_apply_circuit2_fast2") { qc6_18.apply_circuit_fast2(qcirc2_18); };
}
