// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

// DO NOT EDIT! This file was generated by CustomTasks.DependencyPropertyCodeGen
#include "pch.h"
#include "common.h"
#include "ColumnMajorUniformToLargestGridLayout.h"

namespace winrt::Microsoft::UI::Xaml::Controls::Primitives
{
    CppWinRTActivatableClassWithDPFactory(ColumnMajorUniformToLargestGridLayout)
}

#include "ColumnMajorUniformToLargestGridLayout.g.cpp"

GlobalDependencyProperty ColumnMajorUniformToLargestGridLayoutProperties::s_ColumnSpacingProperty{ nullptr };
GlobalDependencyProperty ColumnMajorUniformToLargestGridLayoutProperties::s_MaxColumnsProperty{ nullptr };
GlobalDependencyProperty ColumnMajorUniformToLargestGridLayoutProperties::s_RowSpacingProperty{ nullptr };

ColumnMajorUniformToLargestGridLayoutProperties::ColumnMajorUniformToLargestGridLayoutProperties()
{
    EnsureProperties();
}

void ColumnMajorUniformToLargestGridLayoutProperties::EnsureProperties()
{
    if (!s_ColumnSpacingProperty)
    {
        s_ColumnSpacingProperty =
            InitializeDependencyProperty(
                L"ColumnSpacing",
                winrt::name_of<double>(),
                winrt::name_of<winrt::ColumnMajorUniformToLargestGridLayout>(),
                false /* isAttached */,
                ValueHelper<double>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnColumnSpacingPropertyChanged));
    }
    if (!s_MaxColumnsProperty)
    {
        s_MaxColumnsProperty =
            InitializeDependencyProperty(
                L"MaxColumns",
                winrt::name_of<int>(),
                winrt::name_of<winrt::ColumnMajorUniformToLargestGridLayout>(),
                false /* isAttached */,
                ValueHelper<int>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnMaxColumnsPropertyChanged));
    }
    if (!s_RowSpacingProperty)
    {
        s_RowSpacingProperty =
            InitializeDependencyProperty(
                L"RowSpacing",
                winrt::name_of<double>(),
                winrt::name_of<winrt::ColumnMajorUniformToLargestGridLayout>(),
                false /* isAttached */,
                ValueHelper<double>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnRowSpacingPropertyChanged));
    }
}

void ColumnMajorUniformToLargestGridLayoutProperties::ClearProperties()
{
    s_ColumnSpacingProperty = nullptr;
    s_MaxColumnsProperty = nullptr;
    s_RowSpacingProperty = nullptr;
}

void ColumnMajorUniformToLargestGridLayoutProperties::OnColumnSpacingPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ColumnMajorUniformToLargestGridLayout>();
    winrt::get_self<ColumnMajorUniformToLargestGridLayout>(owner)->OnColumnSpacingPropertyChanged(args);
}

void ColumnMajorUniformToLargestGridLayoutProperties::OnMaxColumnsPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ColumnMajorUniformToLargestGridLayout>();

    auto value = winrt::unbox_value<int>(args.NewValue());
    auto coercedValue = value;
    winrt::get_self<ColumnMajorUniformToLargestGridLayout>(owner)->ValidateGreaterThanZero(coercedValue);
    if (value != coercedValue)
    {
        sender.SetValue(args.Property(), winrt::box_value<int>(coercedValue));
        return;
    }

    winrt::get_self<ColumnMajorUniformToLargestGridLayout>(owner)->OnMaxColumnsPropertyChanged(args);
}

void ColumnMajorUniformToLargestGridLayoutProperties::OnRowSpacingPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::ColumnMajorUniformToLargestGridLayout>();
    winrt::get_self<ColumnMajorUniformToLargestGridLayout>(owner)->OnRowSpacingPropertyChanged(args);
}

void ColumnMajorUniformToLargestGridLayoutProperties::ColumnSpacing(double value)
{
    static_cast<ColumnMajorUniformToLargestGridLayout*>(this)->SetValue(s_ColumnSpacingProperty, ValueHelper<double>::BoxValueIfNecessary(value));
}

double ColumnMajorUniformToLargestGridLayoutProperties::ColumnSpacing()
{
    return ValueHelper<double>::CastOrUnbox(static_cast<ColumnMajorUniformToLargestGridLayout*>(this)->GetValue(s_ColumnSpacingProperty));
}

void ColumnMajorUniformToLargestGridLayoutProperties::MaxColumns(int value)
{
    int coercedValue = value;
    static_cast<ColumnMajorUniformToLargestGridLayout*>(this)->ValidateGreaterThanZero(coercedValue);
    static_cast<ColumnMajorUniformToLargestGridLayout*>(this)->SetValue(s_MaxColumnsProperty, ValueHelper<int>::BoxValueIfNecessary(coercedValue));
}

int ColumnMajorUniformToLargestGridLayoutProperties::MaxColumns()
{
    return ValueHelper<int>::CastOrUnbox(static_cast<ColumnMajorUniformToLargestGridLayout*>(this)->GetValue(s_MaxColumnsProperty));
}

void ColumnMajorUniformToLargestGridLayoutProperties::RowSpacing(double value)
{
    static_cast<ColumnMajorUniformToLargestGridLayout*>(this)->SetValue(s_RowSpacingProperty, ValueHelper<double>::BoxValueIfNecessary(value));
}

double ColumnMajorUniformToLargestGridLayoutProperties::RowSpacing()
{
    return ValueHelper<double>::CastOrUnbox(static_cast<ColumnMajorUniformToLargestGridLayout*>(this)->GetValue(s_RowSpacingProperty));
}
