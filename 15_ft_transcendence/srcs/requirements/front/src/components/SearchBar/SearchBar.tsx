import React from 'react'

interface SearchBarProps {
	searchTerm: string,
	onChange: (newSearchTerm: string) => void
}

const SearchBar = ({ searchTerm, onChange }: SearchBarProps) => {
	const handleInputChange = (event: React.ChangeEvent<HTMLInputElement>) => {
		const newSearchTerm = event.target.value
		onChange(newSearchTerm)
	}

	return ( <input className="solid-frame search-frame search-input-frame text-content" value={searchTerm} onChange={handleInputChange} /> )
}

export default SearchBar