#include <gtest/gtest.h>

#include "contour_map.hpp"
#include "scores/contour_quality.hpp"
#include "test_utils/test_images.hpp"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>

#include "file_utils.hpp"

TEST(ContourExtractionTest, CoverageTest)
{
    for (const auto& image : TestUtils::getTestImages())
    {
        auto preprocessedImage = Contour::adaptivePreprocessImage(image);
        auto contour = Contour::findContourPoints(preprocessedImage);
        float coverage = Scores::ContourQuality::calculateContourCoverage(contour, image);
        ASSERT_LE(coverage, 0.05);
    }
}
