#include <gtest/gtest.h>

namespace data_structures
{
struct MinHeapTest : testing::Test
{
    const double resolution = 1.;
    const double tolerance = 1.e-8;
    const float fill_value = 255.f;
    const float empty_value = 0.f;
    const std::string layer_name = "dynamic";
    const std::unique_ptr<DynamicObjectsRenderer> object_renderer =
        std::make_unique<DynamicObjectsRenderer>(resolution, fill_value, empty_value, layer_name);
};

TEST_F(MinHeapTest, single_node_in_heap)
{
    // create bounding box and 3D predictions data and messages
    std::array<double, 3> dimensions = { 4, 6, 7 };
    auto single_object = DynamicObjectBuilder().with_dimensions(dimensions).build();

    // set up messages
    auto all_objects = DynamicObjectCollectionBuilder().with_objects({*single_object}).build();

    // draw dynamic objects (i.e., execute code under test)
    const unsigned int size_x = 11;
    const unsigned int size_y = 11;
    grid_map::GridMap map({ layer_name });
    map.setGeometry(grid_map::Length(size_x, size_y), resolution, grid_map::Position(0.0, 0.0));
    tf2::Transform object2grid = tf2::Transform::getIdentity();
    object_renderer->DrawDynamicObjects(map, all_objects, object2grid);

    // define the expected output in openCV frame, i.e., transposed
    Eigen::MatrixXf expected(size_x, size_y);
    expected << 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, fill_value, fill_value, fill_value, fill_value, fill_value, fill_value, fill_value, 0, 0,
                0, 0, fill_value, fill_value, fill_value, fill_value, fill_value, fill_value, fill_value, 0, 0,
                0, 0, fill_value, fill_value, fill_value, fill_value, fill_value, fill_value, fill_value, 0, 0,
                0, 0, fill_value, fill_value, fill_value, fill_value, fill_value, fill_value, fill_value, 0, 0,
                0, 0, fill_value, fill_value, fill_value, fill_value, fill_value, fill_value, fill_value, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;

    // compare the output contains the box as expected
    Eigen::MatrixXf actual = map[layer_name];
    ASSERT_THAT(actual, MatrixFloatEq((Eigen::Matrix<float, size_x, size_y>() << expected).finished()));
}
}
