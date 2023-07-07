import React from "react";
import { NavLink } from 'react-router-dom';
import "./SolidFrame.scss";

type SolidFrameProps = {
	frameClass?: string;
	onClick?: () => void;
	txtClass?: string;
	txt1?: string;
	txt2?: string;
	children?: React.ReactNode;
	link?: string;
}

function SolidFrame({
		frameClass,
		onClick,
		txtClass,
		txt1,
		txt2,
		link,
		children,
	}: SolidFrameProps) {

	return (
		<div className={`solid-frame ${frameClass}`} >
		{children}
			<div className={`text-content ${txtClass}`}>
				<p className='color1' onClick={onClick} >
					{txt1}
				</p>
				<p className='color2' onClick={onClick} >
					{link ? (
							<NavLink to={link}>{txt2}</NavLink>
						) : (
							<>{txt2}</>
						)
					}
				</p>
			</div>
		</div>
	);
}

export default SolidFrame;
